#include <iostream>

#include "ComputePipeline.h"

int main() {
    std::cout << "Hello, I'm a CompilePipeline main..." << std::endl;

    ComputePipeline pipeline;

    pipeline.addAction(Actions::sumVals);
    pipeline.addAction(Actions::multiplyVals);

    std::vector<int> data = {1, 2, 3, 4, 5};

    std::cout << "Input: 1 2 3 4 5" << std::endl;
    pipeline.executeActions(data);

    return EXIT_SUCCESS;
}