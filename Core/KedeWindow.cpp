#include "KedeWindow.h"

#include <stdexcept>

KedeWindow::KedeWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
{
    initWindow();
}

KedeWindow::~KedeWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void KedeWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
{
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create window surface");
    }
}

void KedeWindow::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}
