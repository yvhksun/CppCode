#pragma once
#include "vulkan/vulkan.hpp"
#include<vector>
class Pipeline
{
private:
    /* data */
    vk::Device logicContext;
public:
    Pipeline(vk::Device device);
    ~Pipeline();
    vk::Pipeline CreatePipeline(const char* vertexpaht,const char*fragmentPath);
private:
    std::vector<vk::PipelineShaderStageCreateInfo> LoadShaders(const char* vertexpaht,const char*fragmentPath);
    vk::PipelineShaderStageCreateInfo LoadModule(const char* path, vk::ShaderStageFlagBits stageType);
    std::vector<uint32_t> GetCode(const char * path);
};

