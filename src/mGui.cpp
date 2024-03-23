#include "mGui.h"
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include <examples/imgui_impl_opengl3.cpp>
#include <examples/imgui_impl_glfw.cpp>

void mGui::init(GLFWwindow* window)
{
    // 设置上下文
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // 启用键盘控制
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // 启用游戏手柄控制
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // 开启窗口悬停功能
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // 开启UI可以渲染viewport外的功能

    // Setup Platform/Renderer backends(后端)
    ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();
}

void mGui::Begin()
{
   // 渲染主循环开始时渲染UI所需调用的函数
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void mGui::RenderUI()
{
    // 渲染UI
    ImGui::ShowDemoWindow(); // Demo窗口
}

void mGui::End()
{
    ImGuiIO& io = ImGui::GetIO();
 
    //渲染结束时必须执行的函数
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)// 当开启该项功能时需要注意的事项
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}

void mGui::Shutdown()
{
    // 销毁资源
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
