#ifndef COMPUTE_PIPELINE_H
#define COMPUTE_PIPELINE_H

#include <vector>

#include <Actions.h>

class ComputePipeline {
public:
    bool init();

    void addAction(Actions::Action action);
    void executeActions(std::vector<int>& data);

    void cleanup();

private:
    std::vector<Actions::Action> actions;
};

#endif