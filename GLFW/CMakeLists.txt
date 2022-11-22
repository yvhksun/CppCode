cmake_minimum_required(VERSION 3.22)

#project(WindowUI VERSION 1.0)

add_definitions(-DGLFW_EXPOSE_NATIVE_WIN32)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} ALL_SOURCE)


set(CMAKE_MODULE_PATH ../cmake)
#glfw引入
find_package(GLFW REQUIRED)
list(APPEND INCLUDE_DIRS ${GLFW_INCLUDE_DIR})
list(APPEND CUS_LIBRARYS ${GLFW_LIBRARY})


add_definitions(-DVK_VERSION_1_0)
include(../Vulkan/CMakeLists.txt)
list(APPEND INCLUDE_DIRS  ${Vulkan_path}/Include)
list(APPEND CUS_LIBRARYS ${Vulkan_LIBRARY})


set(publish ${CMAKE_CURRENT_SOURCE_DIR}/publish/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${publish})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${publish})



add_library(WindowUI SHARED ${ALL_SOURCE})
target_include_directories(WindowUI PUBLIC ${INCLUDE_DIRS})
target_link_libraries(WindowUI "${CUS_LIBRARYS}")  



add_custom_command(TARGET WindowUI POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy ${CUS_LIBRARYS} ${publish}
                    COMMAND ${CMAKE_COMMAND} -E copy_directory ${GLFW_BIN_DIR} ${publish}
                    )

