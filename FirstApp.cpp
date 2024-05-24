#include "FirstApp.h"

FirstApp::FirstApp()
{
    CreatePipelineLayout();
    CreatePipeline();
    CreateCommandBuffers();
}

FirstApp::~FirstApp()
{
    vkDestroyPipelineLayout(kedeDevice.device(), kedePipelineLayout, nullptr);
}

void FirstApp::Run()
{
    while (!kedeWindow.shouldClose())
    {
        glfwPollEvents();
    }
}

void FirstApp::CreatePipelineLayout()
{
    VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo{};
    pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipelineLayoutCreateInfo.setLayoutCount = 0;
    pipelineLayoutCreateInfo.pSetLayouts = nullptr;
    pipelineLayoutCreateInfo.pushConstantRangeCount = 0;
    pipelineLayoutCreateInfo.pPushConstantRanges = nullptr;

    if (vkCreatePipelineLayout(kedeDevice.device(), &pipelineLayoutCreateInfo, nullptr, &kedePipelineLayout) != VK_SUCCESS)
    {
        throw std::exception("failed to create pipeline layout");
    }
    
}

void FirstApp::CreatePipeline()
{
    auto pipelineConfig = KedePipeline::defaultPipelineConfigInfo(kedeSwapchain.width(), kedeSwapchain.height());
    pipelineConfig.renderPass = kedeSwapchain.getRenderPass();
    pipelineConfig.pipelineLayout = kedePipelineLayout;

    kedePipeline = std::make_unique<KedePipeline>(kedeDevice, "Shaders/simpleshader.vert.spv", "Shaders/simpleshader.frag.spv", pipelineConfig);
}

void FirstApp::CreateCommandBuffers()
{
}

void FirstApp::DrawFrame()
{
}
