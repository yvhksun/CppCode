cmake_minimum_required(VERSION 3.22)
project(libMyVulkan)

set(publish ${CMAKE_CURRENT_SOURCE_DIR}/publish/bin)
set(publish_include ${CMAKE_CURRENT_SOURCE_DIR}/publish/include)

file(GLOB ALL_HEADS *.hpp *.h)
file(GLOB ALL_SOURCE *.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${publish})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${publish})

add_library(MyVulkan SHARED ${ALL_SOURCE})


add_definitions(-DVK_VERSION_1_0)
add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)

include(../Vulkan/CMakeLists.txt)
list(APPEND INCLUDE  ${Vulkan_path}/Include)
list(APPEND LIBPath ${Vulkan_LIBRARY})


target_include_directories(MyVulkan PUBLIC ${INCLUDE})

target_link_libraries(MyVulkan
   ${LIBPath}
)




file(COPY ${ALL_HEADS} DESTINATION ${publish_include})

add_custom_command(TARGET MyVulkan POST_BUILD
                  COMMAND ${CMAKE_COMMAND} -E copy ${Vulkan_LIBRARY} $<TARGET_FILE_DIR:MyVulkan>
                  )
