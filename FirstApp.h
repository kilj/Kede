#pragma once
#include "Core/KedePipeline.h"
#include "Core/KedeWindow.h"

class FirstApp
{
public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    void Run();
    
private:
    KedeWindow kedeWindow{WIDTH, HEIGHT, "Hello, V!"};
    KedeDevice kedeDevice{kedeWindow};
    
    KedePipeline kedePipepline{kedeDevice, "Shaders/simpleshader.vert.spv", "Shaders/simpleshader.frag.spv", KedePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
};
