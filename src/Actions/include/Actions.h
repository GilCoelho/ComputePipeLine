#ifndef ACTIONS_H
#define ACTIONS_H

#include <vector>
#include <functional>

namespace Actions {
    using Action = std::function<void(std::vector<int>&)>;

    void sumVals(std::vector<int>& data);
    void multiplyVals(std::vector<int>& data);
    void printVals(std::vector<int>& data);
}

#endif
