#include"Pipeline.h"
#include<fstream>
#include<iostream>
Pipeline::Pipeline(vk::Device device)
{
    this->logicContext = device;
}

Pipeline::~Pipeline()
{
}

vk::Pipeline Pipeline::CreatePipeline(const char* vertexpaht,const char*fragmentPath){
    auto stages = LoadShaders( vertexpaht,fragmentPath);
    vk::GraphicsPipelineCreateInfo info;
    info.setStages(stages);
    auto pipelineContext = logicContext.createGraphicsPipeline(nullptr,info);
    return pipelineContext;
}

 std::vector<vk::PipelineShaderStageCreateInfo> Pipeline::LoadShaders(const char* vertexpaht,const char*fragmentPath){
    auto fragment =  LoadModule(fragmentPath,vk::ShaderStageFlagBits::eFragment);
    auto vertex = LoadModule(vertexpaht,vk::ShaderStageFlagBits::eVertex);

   
    std::vector<vk::PipelineShaderStageCreateInfo> stages ;
    stages.push_back(fragment);
    stages.push_back(vertex);
    return stages;
  

 }

vk::PipelineShaderStageCreateInfo Pipeline::LoadModule(const char* path, vk::ShaderStageFlagBits stageType){
    auto code = GetCode(path);
    vk::ShaderModuleCreateInfo info ;
    info.setCode(code);
    vk::ShaderModule shadermodule = logicContext.createShaderModule(info);
    vk::PipelineShaderStageCreateInfo shaderStage;
    shaderStage.setStage(stageType).setModule(shadermodule);
  
    return shaderStage;
}
std::vector<uint32_t> Pipeline::GetCode(const char * path){
    std::string testPath = "./vert.spv";
    std::ifstream fs (testPath,std::ios::ate|std::ios::binary);
    std::cout<< path<<std::endl;
    if(!fs.is_open())
    {
        throw std::runtime_error("faild to open file");
    }

    size_t len = (size_t)fs.tellg();
    std::vector<char> buffer(len);
    fs.seekg(0);
    fs.read(buffer.data(),len);
    fs.close();
    auto temp = reinterpret_cast<uint32_t*>(buffer.data());

    std::vector<uint32_t> result(temp,temp+len);
    return result;
}