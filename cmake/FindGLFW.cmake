

find_path(GLFW_INCLUDE_DIR "glfw3.h" ${PROJECT_SOURCE_DIR}/Third_party/GLFW/include/GLFW)
find_library(GLFW_LIBRARY "libglfw3dll.a" "${PROJECT_SOURCE_DIR}/Third_party/GLFW/lib-mingw-w64/")

find_path(GLFW_BIN_DIR  "libglfw3dll.a" "${PROJECT_SOURCE_DIR}/Third_party/GLFW/lib-mingw-w64/")




set(GLFW_FOUNT FALSE)
if(GLFW_INCLUDE_DIR AND GLFW_LIBRARY)
    string(REGEX REPLACE "/include/GLFW" "" GLFW_INCLUDE_DIR ${GLFW_INCLUDE_DIR})
    set(GLFW_INCLUDE_DIR ${GLFW_INCLUDE_DIR}/include)
    set(GLFW_FOUNT TRUE)
endif()
message(STATUS GLFW_INCLUDE_DIR:  ${GLFW_INCLUDE_DIR})
message(STATUS GLFW_LIBRARY: ${GLFW_LIBRARY})