#include<iostream>
#include"MyvkConfig.h"

#include"MyVulkan/VulkanContext.h"
#include"GLFW/Win32Instance.h"
#include<libloaderapi.h>
using namespace std;


//  1. 创建程序窗口 
//  2. 初始化Vulkan实例 - 完成对vulkan库的初始化 
//  3. 初始化输出表面 - 指明渲染显示目的地 
//  4. 枚举vulkan支持的物理设备并选择满足要求的物理设备（需要查询其是否支持指定特性以及支持程度，可能存在多个vulkan支持的设备。对于渲染程序，通常需要物理设备支持图形队列以及表面呈现队列）
//  5. 创建逻辑设备 - 根据指定物理设备即可创建逻辑设备（逻辑设备和物理设备相对应，但并不唯一。需要指出的是在创建逻辑设备时需要指定开启那些特性。如果需要使用细分着色器则在这个步骤需要开启之。逻辑设备可能是vulkan中最常用的对象了，大部分vulkan对象都需要使用逻辑设备来完成创建工作）
//  6. 创建指令池对象 - vulkan中指令提交和传输需要通过指令缓冲来操作，对于指令缓冲需要构建指令池对象 
//  7. 创建交换链 - vulkan中不存在默认帧缓冲的概念，需要一个缓存渲染缓冲的组件，这就是交换链。交换链本质上一个包含了若干等待呈现的图像的队列 
//  8. 创建交换队列图像视图 - 有了交换链还不够，需要一组图形来保存渲染数据 
//  9. 创建渲染通道 - 渲染通道用于表示帧缓冲，他是子通道以及子通道关系的集合。深度模板附件、颜色附件、帧附件都是在此阶段被创建的 
//  10. 创建描述符设置布局 - 描述符是一个特殊的不透明的着色器变量，着色器使用它以间接的方式访问缓冲区和图像资源。描述符集合是描述一个管线使用到的描述符集合。描述符布局则用于刻画其布局。 
//  11. 创建管线布局 - 管道布局包含一个描述符集合布局的列表。推送常量在这个阶段被设置。 
//  12. 创建帧缓冲 - 作为附件的图像依赖交换链用于呈现时返回的图像。这意味着我们必须为交换链中的所有图像创建一个帧缓冲区，并在绘制的时候使用对应的图像。其附件必须和渲染通道中使用的附件相匹配。 
//  13. 创建描述符池 -描述符不能直接创建，需要从池中分配 
//  14. 创建描述符集 - 描述符池是根据交换链帧个数以及具体Shader中描述符数量和数据来创建的，着色器属性类型和其中涉及的uninform、location等信息是在这个阶段被传入的 
//  15. 分配和更行描述符集 - 根据交换链帧个数、uniform数据以及图形视图是在这个阶段被处理的 
//  16. 创建管线 - 根据Shader、管线布局、渲染通道以及其他相关信息即可构造管线 
//  17. 创建命令缓冲 - 根据命令池、渲染通道、交换链帧个数即可分配并使用命令缓冲，其中对管线的绑定、描述符集的绑定以及开始和结束渲染通道是在这个阶段完成的。从某种意义上讲，这块类似早期OpenGL中的显示列表，决定了最终的渲染效果









int main(int argc,char* argv[]){


   
    WindowsUI::Win32Instance instance ;
    instance.InitWindow();
    

    HWND hWnd = instance.GetHwnd();
    HINSTANCE hInstance = GetModuleHandle(nullptr);
    VulkanContext context(hWnd,hInstance);

    auto result = instance.GetUiExtension();
    context.SetSurfaceExtensions(result);

    context.Init();

    instance.Loop([&context ]()->void {
            context.Loop();
    });
}