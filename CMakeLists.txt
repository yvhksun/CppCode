cmake_minimum_required(VERSION 3.7.0)
project(MyVK VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -fexec-charset=GBK")

set(RUNTIME_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${RUNTIME_PATH})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${RUNTIME_PATH})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${RUNTIME_PATH})

add_subdirectory(MyVulkan)
add_subdirectory(GLFW)

# add directory to the object 
list(APPEND EXTRA_INCLUDE "${PROJECT_SOURCE_DIR}/Bulid")
list(APPEND EXTRA_INCLUDE "${PROJECT_SOURCE_DIR}/MyVulkan")
list(APPEND EXTRA_LIBS MyVulkan)
list(APPEND EXTRA_LIBS WindowUI)

list(APPEND COPY_PATH "${PROJECT_SOURCE_DIR}/MyVulkan/publish/bin")
list(APPEND COPY_PATH "${PROJECT_SOURCE_DIR}/GLFW/publish/bin")

# config  a header file to pass some of the cmake settings
# to the source code 
configure_file(MyvkConfig.h.in MyvkConfig.h)

# create executable named MyVK
add_executable(MyVK main.cpp)

# link libraries to executable
target_link_libraries(MyVK
  ${EXTRA_LIBS}
) 

set(CMKAE_B_OUTPUT)

target_include_directories(MyVK PUBLIC "${PROJECT_BINARY_DIR}" "${EXTRA_INCLUDE}")

add_custom_command(TARGET MyVK POST_BUILD
                  COMMAND ${CMAKE_COMMAND} -E copy_directory ${COPY_PATH} ${RUNTIME_PATH})