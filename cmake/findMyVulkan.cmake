# 头文件
find_path(MyVulkan_INCLUDE_DIR VulkanContext.h "../MyVulkan/publish/include")
#动态库
find_library(MyVulkan_LIBRARY libMyVulkan "../MyVulkan/publish/bin")
message(STATUS MyVulkan_LIBRARY${MyVulkan_LIBRARY})
set(MyVulkan_FOUND FALSE)
if(MyVulkan_LIBRARY AND MyVulkan_INCLUDE_DIR)
    set(MyVulkan_FOUND TRUE)
endif()
