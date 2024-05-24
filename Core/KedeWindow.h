#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

class KedeWindow
{
public:
    KedeWindow(int w, int h, std::string name);
    ~KedeWindow();

    KedeWindow(const KedeWindow&) = delete;
    KedeWindow& operator=(const KedeWindow&) = delete;

    bool shouldClose() { return glfwWindowShouldClose(window); }
    void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
    VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }

private:
    void initWindow();

    const int width;
    const int height;

    std::string windowName;

    GLFWwindow* window;
};
