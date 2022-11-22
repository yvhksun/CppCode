#include"Win32Instance.h"
#include<iostream>
using namespace WindowsUI;
Win32Instance::Win32Instance(/* args */)
{
    mywindow    = nullptr;
    width = 700;
    height= 580;
}

Win32Instance::~Win32Instance()
{
    if (mywindow)
    {
        std::cout<<"关闭窗口"<<std::endl;
        glfwDestroyWindow(mywindow); 
        glfwTerminate();
    }
    
}

void Win32Instance::InitWindow(){
    int result =  glfwInit();
    glfwInitHint(GLFW_CLIENT_API,GLFW_NO_API);
    glfwInitHint(GLFW_RESIZABLE,GLFW_FALSE);
    mywindow = glfwCreateWindow(width,height,"ssssss",nullptr,nullptr);
}

std::vector<const char*> Win32Instance::GetUiExtension(){
    uint32_t count = 0 ;
    auto ext = glfwGetRequiredInstanceExtensions(&count);
    std::vector<const char*> result (ext,ext+count);
    return result;
}

