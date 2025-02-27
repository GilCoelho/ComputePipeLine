#ifndef COMPUTE_PIPELINE_H
#define COMPUTE_PIPELINE_H

#include <memory>
#include <vector>

#include <Actions.h>

class ComputePipeline {
public:
    void init(const std::string& uri);

    void addAction(std::shared_ptr<actions::IAction> new_action);
    void executeActions(std::vector<int>& data);

    void cleanup();

private:
    std::vector<std::shared_ptr<actions::IAction>> actions_to_execute;
};

#endif
