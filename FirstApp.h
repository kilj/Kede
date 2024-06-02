#pragma once
#include "Core/KedePipeline.h"
#include "Core/KedeWindow.h"
#include "Core/KedeSwapChain.h"
#include <memory>
#include <vector> //not used?

class FirstApp
{
public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    FirstApp();
    ~FirstApp();
    FirstApp(const FirstApp&) = delete;
    FirstApp &operator=(const FirstApp&) = delete;
    
    void Run();
    
private:
    void CreatePipelineLayout();
    void CreatePipeline();
    void CreateCommandBuffers();
    void DrawFrame();
    
    KedeWindow kedeWindow{WIDTH, HEIGHT, "Hello, V!"};
    KedeDevice kedeDevice{kedeWindow};
    KedeSwapChain kedeSwapChain{kedeDevice, kedeWindow.getExtent()};

    std::unique_ptr<KedePipeline> kedePipeline;
    VkPipelineLayout kedePipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
};
