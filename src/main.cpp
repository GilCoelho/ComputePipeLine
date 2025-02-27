#include <iostream>

#include "ComputePipeline.h"

int main() {
    std::cout << "Hello, I'm a CompilePipeline main..." << std::endl;

    std::string path = "http://path/to/file";

    ComputePipeline pipeline;

    pipeline.init(path);
    // auto t_action = actions::IAction();
    // t_action.load(path).execute();

    pipeline.addAction(actions::sumVals);
    pipeline.addAction(actions::multiplyVals);

    std::vector<int> data = {1, 2, 3, 4, 5};

    std::cout << "Input: 1 2 3 4 5" << std::endl;
    pipeline.executeActions(data);

    pipeline.cleanup();

    return EXIT_SUCCESS;
}
