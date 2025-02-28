#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <functional>
#include <iostream>

namespace actions {
    template<typename T>
    using ActionFunction = std::function<T(std::vector<T>&)>;

    enum class ActionTypes
    {
        ImageDecode,
        Decompression,
        JSONDeserialize,
    };

    struct actionData {
        ActionTypes type;
        std::string data;
        std::vector<ActionFunction<int>> func_action;
    };

    class IAction {
        public:
            IAction(const actionData& data) {};
            ~IAction() = default;

            // template <typename T>
            // IAction& execute(T data);
            IAction& execute(std::vector<int>& data);

            virtual void p() = 0;

        protected:
            ActionTypes action_type;
            std::string data_txt = "I'm an IAction";
            std::vector<ActionFunction<int>> custom_action;
    };


    // Testing functions
    template<typename T>
    T sumVals(std::vector<T>& data) {
        T sum = 0;
        for (const auto& val : data) sum += val;
        std::cout << "Total sum: " << sum << std::endl;
        return sum;
    }

    template<typename T>
    T multiplyVals(std::vector<T>& data) {
        T mult = 1;
        for (const auto& val : data) mult = mult * val;
        std::cout << "Total Multiplication: " << mult << std::endl;
        return mult;
    }
}

#endif
