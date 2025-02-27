#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <functional>

namespace actions {
    // ActionTypes enum class
    enum class ActionTypes
    {
        ImageDecode,
        Decompression,
        JSONDeserialize,
    };
    // ----------------------------

    class IAction {
        public:
            virtual IAction& execute() = 0;

        protected:
            ActionTypes type;
            std::string data = "I'm an IAction";
    };

    using Action = std::function<void(std::vector<int>&)>;

    void sumVals(std::vector<int>& data);
    void multiplyVals(std::vector<int>& data);
    void printVals(std::vector<int>& data);
}

#endif
