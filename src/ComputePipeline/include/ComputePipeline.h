#ifndef COMPUTE_PIPELINE_H
#define COMPUTE_PIPELINE_H

#include <vector>

#include <Actions.h>

class ComputePipeline {
public:
    void addAction(Actions::Action action);
    void executeActions(std::vector<int>& data);

private:
    std::vector<Actions::Action> actions;
};

#endif