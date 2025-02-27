#include "ComputePipeline.h"
#include <loader.h>

bool ComputePipeline::init(const std::string& uri) {
    auto builder = loader::buildUriObjs(uri);
    auto action = builder(uri);
    action->execute();
    return true;
}

void ComputePipeline::addAction(actions::Action action) {
    actions.push_back(action);
}

void ComputePipeline::executeActions(std::vector<int>& data) {
    for (auto& action : actions) {
        action(data);
    }
}

void ComputePipeline::cleanup() {
}
