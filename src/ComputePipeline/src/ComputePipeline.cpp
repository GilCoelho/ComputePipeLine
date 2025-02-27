#include "ComputePipeline.h"

bool ComputePipeline::init() {
    return true;
}

void ComputePipeline::addAction(Actions::Action action) {
    actions.push_back(action);
}

void ComputePipeline::executeActions(std::vector<int>& data) {
    for (auto& action : actions) {
        action(data);
    }
}

void ComputePipeline::cleanup() {
}