#include"VulkanContext.h"
#include<iostream>
#include"Pipeline.h"

VulkanContext::VulkanContext(HWND hWnd,HINSTANCE hInstance)
{
    this->hWnd  = hWnd;
    this->hInstance = hInstance;
}

VulkanContext::~VulkanContext()
{
    if(contxt){
        if (logicDevice)
        {
            if(imageviews.size()>0)
            {
                for (auto i : imageviews)
                {
                    logicDevice.destroyImageView(i);
                }
                
            }
            if (swapchain)
            {
                logicDevice.destroySwapchainKHR(swapchain);
            }
            if (pipeline)
            {
                logicDevice.destroyPipeline(pipeline);
            }
            
            logicDevice.destroy();
        }
        
        if (surface)
        {
            contxt.destroySurfaceKHR(surface);
            /* code */
        }
       
        
        
        contxt.destroy();
    }
}

void VulkanContext::Init(){
    vk::ApplicationInfo app;
    vk::InstanceCreateInfo info;
    info.setPApplicationInfo(&app);
    info.setPEnabledExtensionNames(surfaceExtensions);
    auto layers = GetLayers();
    info.setPEnabledLayerNames(layers);

    contxt = vk::createInstance(info);
    SetDebugValidCallback();
    
    CreateSurface();
    CreateLogicDevice();
    CreateSwapchain();

     Pipeline p (logicDevice);
     this->pipeline =  p.CreatePipeline(".\\vert.spv",".\\frag.spv");
}
void VulkanContext::Loop(){
    //std::cout<<"wgireoher"<<std::endl;
}

void VulkanContext::SetSurfaceExtensions(std::vector<const char*> extensions){
    surfaceExtensions = extensions;
}


std::vector<const char*> VulkanContext::GetLayers()
{
	
	std::vector<const char*> result = { "VK_LAYER_KHRONOS_validation",
										"VK_LAYER_LUNARG_standard_validation",
										};
	return result;
}



void VulkanContext::SetDebugValidCallback(){
    vk::DebugReportCallbackCreateInfoEXT info;
    info.setFlags(vk::DebugReportFlagBitsEXT::eError|vk::DebugReportFlagBitsEXT::eWarning)
    .setPfnCallback(callback);
}

void VulkanContext::CreateLogicDevice(){
    phyDevice = pickDeivce();
    auto layers = GetLayers();
    std::vector<vk::DeviceQueueCreateInfo> queueinfos ;
    float priory = 1.0f;
    vk::DeviceQueueCreateInfo graphicinfo = vk::DeviceQueueCreateInfo()
                                            .setQueueFamilyIndex(queueProperties.queueindex)
                                            .setQueueCount(queueProperties.props.queueCount)
                                            , presentinfo;
    graphicinfo.pQueuePriorities = &priory;
    queueinfos.push_back(graphicinfo);
    if (queueProperties.persentindex!= queueProperties.queueindex )
    {
        presentinfo .setQueueFamilyIndex(queueProperties.persentindex)
                    .setQueueCount(1);
        presentinfo.pQueuePriorities = &priory;
        queueinfos.push_back(presentinfo);
    }
    std::vector<const char*> result = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
    vk::DeviceCreateInfo info = vk::DeviceCreateInfo()
                                .setPEnabledLayerNames(layers)
                                .setPEnabledExtensionNames(result)
                                .setQueueCreateInfos(queueinfos);
                                
    logicDevice = phyDevice.createDevice(info);
   
    //vk::ImageViewCreateInfo info;
}

vk::PhysicalDevice VulkanContext::pickDeivce(){
    auto devices = contxt.enumeratePhysicalDevices();
    
    for(const auto& device :devices)
    {

        auto queues = device.getQueueFamilyProperties();
        auto features =  device.getFeatures();

        int i= 0;
        bool queueFlag = false;
        bool presentFlag = false;
        for(const auto& queue : queues)
        {
            if (queue.queueFlags & vk::QueueFlagBits::eGraphics&&features.geometryShader)
            {
                queueProperties.queueindex = i;
                queueProperties.props= queue;
                queueFlag = true;
                return device;
            }
           
            if(device.getSurfaceSupportKHR(i,surface))
            {
                queueProperties.persentindex = i;
                presentFlag = true;
            }

            
            if (presentFlag&& queueFlag)
            {
                return device;
            }
            
            i++;
        }
    }
    
    return devices[0];
}

void VulkanContext::CreateCommandPool(){
    auto queue = logicDevice.getQueue(queueProperties.queueindex,0);
    vk::CommandBuffer buffer = vk::CommandBuffer();
    vk::SubmitInfo info = vk::SubmitInfo().setCommandBuffers(buffer);
    queue.submit(info);
}

void VulkanContext::CreateSwapchain(){
   auto capabilities = phyDevice.getSurfaceCapabilitiesKHR(surface);
   queueProperties.extend =  capabilities.currentExtent;
   auto format = phyDevice.getSurfaceFormatsKHR(surface);
   queueProperties.format =format[0];

    vk::SwapchainCreateInfoKHR info ;
    auto presentModel = ChoosePresentMode();

    info.setSurface(surface)
        .setImageFormat(queueProperties.format.format)
        .setClipped(VK_TRUE)
        .setImageUsage(vk::ImageUsageFlagBits::eColorAttachment)
        .setImageExtent(queueProperties.extend)
        .setMinImageCount(2)
        .setImageArrayLayers(1)
        .setPQueueFamilyIndices(&queueProperties.persentindex)
        .setPresentMode(presentModel)
        .setImageColorSpace(queueProperties.format.colorSpace);
        
    swapchain = logicDevice.createSwapchainKHR(info);

    //  auto swapchainImages = logicDevice.getSwapchainImagesKHR(swapchain);

    
    // for (const auto& image :swapchainImages)
    // {
    //     vk::ImageViewCreateInfo viewInfo;
    //     vk::ImageSubresourceRange range ;
    //     range.setAspectMask(vk::ImageAspectFlagBits::eColor).setLevelCount(1).setLayerCount(1);
    //     viewInfo.setImage(image);
    //     viewInfo.setViewType(vk::ImageViewType::e2D).setSubresourceRange(range).setFormat(queueProperties.format.format);
    //     auto imageview = logicDevice.createImageView(viewInfo);
    //     imageviews.push_back(imageview);
    // }
}


vk::PresentModeKHR VulkanContext::ChoosePresentMode(){
    auto persents = phyDevice.getSurfacePresentModesKHR(surface);
    auto result = vk::PresentModeKHR::eFifo;
    for (auto & item : persents )
    {
        if (item == vk::PresentModeKHR::eMailbox)
        {
            return  vk::PresentModeKHR::eMailbox;
        }
        if  (item == vk::PresentModeKHR::eImmediate)
        {
            result = vk::PresentModeKHR::eImmediate;
        }
        
    }
    return result;
    
}