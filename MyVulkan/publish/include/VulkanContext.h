#pragma once
#include<vector>
#include"vulkan/vulkan.hpp"
#include<vulkan/vulkan_funcs.hpp>
#include<iostream>
class VulkanContext
{
private:
    /* data */
    HWND hWnd;
    HINSTANCE hInstance;

    std::vector<const char*> surfaceExtensions;
    vk::Instance contxt;
    vk::SurfaceKHR surface;
    vk::PhysicalDevice phyDevice; 
    vk::Device logicDevice;
    vk::SwapchainKHR swapchain;
    std::vector<vk::ImageView> imageviews;
    vk::Pipeline pipeline;
    struct queueInfo{
        uint32_t queueindex;
        vk::QueueFamilyProperties props;
        uint32_t persentindex;
        vk::Extent2D extend;
        vk::SurfaceFormatKHR format;
    };
    queueInfo  queueProperties;
    vk::PresentModeKHR ChoosePresentMode();
public:
    VulkanContext(HWND,HINSTANCE);
    ~VulkanContext();

    void Init();
    void Loop();
    void SetSurfaceExtensions(std::vector<const char*>);
    std::vector<const char*> GetLayers();
    
    void CreateLogicDevice();
    void CreateCommandPool();
    void CreateSwapchain();
 

    void CreateSurface(){
        vk::Win32SurfaceCreateInfoKHR info ;
        info.setHwnd(hWnd).setHinstance(hInstance);
        surface = contxt.createWin32SurfaceKHR(info);
    }
private:
    vk::PhysicalDevice pickDeivce();
    void SetDebugValidCallback();
    static VKAPI_ATTR VkBool32 VKAPI_CALL  callback(VkFlags   flag,
                                                VkDebugReportObjectTypeEXT objectType,
                                                uint64_t object,
                                                size_t loaction,
                                                int32_t code,
                                                const char* msgPrefix ,
                                                const char* msg,
                                                void * userData){
        std::cout<<msg<<std::endl;
        return VK_FALSE;
    }
};