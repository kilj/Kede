#include "FirstApp.h"

void FirstApp::Run()
{
    while (!kedeWindow.shouldClose())
    {
        glfwPollEvents();
    }
}
