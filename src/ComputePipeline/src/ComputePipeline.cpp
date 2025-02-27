#include "ComputePipeline.h"
#include <loader.h>

void ComputePipeline::init(const std::string& uri) {
    auto builder = loader::buildUriObjs(uri);
    auto new_action = builder(uri);

    this->addAction(new_action);
}

void ComputePipeline::addAction(std::shared_ptr<actions::IAction> new_action) {
    actions_to_execute.push_back(new_action);
}

void ComputePipeline::executeActions(std::vector<int>& data) {
    for (auto& action_to_exe : actions_to_execute) {
        action_to_exe->execute(data);
    }
}

void ComputePipeline::cleanup() {
}
