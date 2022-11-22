#pragma once
#include<vulkan/vulkan.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<GLFW/glfw3native.h>
#include<iostream>
namespace  WindowsUI{

    class Win32Instance
    {
    private:
        /* data */
        int top,left,width,height;
        GLFWwindow * mywindow;
    public:
        Win32Instance(/* args */);
        ~Win32Instance();
        void InitWindow();
        template<typename T>
        void Loop(const T render);
        std::vector<const char*> GetUiExtension();

        HWND GetHwnd(){
            return glfwGetWin32Window(mywindow);
        }
    };
    
    template<typename T>
    void Win32Instance::Loop(const T render){
   // glfwMakeContextCurrent(mywindow);
  
    while ( ! glfwWindowShouldClose(mywindow))
    {
        /* code */
        render();
        // glfwWaitEvents();
        glfwPollEvents();
    }
}
};
