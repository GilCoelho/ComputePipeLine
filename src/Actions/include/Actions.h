#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <functional>

namespace actions {
    using ActionFunction = std::function<void(std::vector<int>&)>;

    enum class ActionTypes
    {
        ImageDecode,
        Decompression,
        JSONDeserialize,
    };

    struct actionData {
        ActionTypes type;
        std::string data;
        ActionFunction func_action;
    };

    class IAction {
        public:
            IAction(const actionData& data) {};

            template <typename T>
            IAction& execute(T data);

        protected:
            ActionTypes action_type;
            std::string data_txt = "I'm an IAction";
            ActionFunction custom_action;
    };


    void sumVals(std::vector<int>& data);
    void multiplyVals(std::vector<int>& data);
    void printVals(std::vector<int>& data);
}

#endif
