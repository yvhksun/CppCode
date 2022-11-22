#define MyVK_Version_Major 0
#define MyVK_Version_Minor 1
#define USE_MATH
#define USE_WINDOWS_VULKAN

#ifdef USE_WINDOWS_VULKAN
#define GLFW_EXPOSE_NATIVE_WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#endif
