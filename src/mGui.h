#pragma once

#include <imgui.h>
#include <GLFW/glfw3.h>

class mGui
{
public:
    void init(GLFWwindow* window);
    void Begin();
    void RenderUI();
    void End();
    void Shutdown();

private:

};