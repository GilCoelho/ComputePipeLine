#include "ComputePipeline.h"

void ComputePipeline::addAction(Actions::Action action) {
    actions.push_back(action);
}

void ComputePipeline::executeActions(std::vector<int>& data) {
    for (auto& action : actions) {
        action(data);
    }
}