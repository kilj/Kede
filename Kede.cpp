#include "FirstApp.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    FirstApp app{};

    try
    {
        app.Run();
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
