option(AUTO_LOCATE_VULKAN "AUTO LOCATE VULKAN" ON)

if(AUTO_LOCATE_VULKAN)
    message(STATUS "Attemting auto locate vulkan using CMAKE")
    find_package(Vulkan)
    if(NOT ${Vulkan_INCLUDE_DIRS} STREQUAL "")
        set(Vulkan_path ${Vulkan_INCLUDE_DIRS})
        string(REGEX REPLACE "/Include" "" Vulkan_path ${Vulkan_path})
        message(STATUS "Load package vulkan success")
    endif()
    if(NOT ${Vulkan_FOUND})
        message(STATUS "failed to locate Vulkan sdk ,retrying again....")
    endif()
    
endif()    
    

add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)