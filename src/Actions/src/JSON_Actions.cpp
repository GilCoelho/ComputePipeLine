#include<JSON_Actions.h>

#include<iostream>

actions::JSONAction::JSONAction(const actions::actionData& data) : actions::IAction(data) {
    this->action_type = data.type;
    this->data_txt = data.data;
    this->custom_action = data.func_action;
}

// template <typename T>
// actions::IAction& actions::JSONAction::execute(T data) {
//     std::cout << this->data << std::endl;
//     return *this;
// };

// template<>
actions::IAction& actions::JSONAction::execute(std::vector<int>& data) {
    for (const auto& func : this->custom_action) {
        auto res = func(data);
        std::cout << this->data_txt << ": " << res << std::endl;
    }

    return *this;
}