#include<Decompress_Actions.h>

#include<iostream>

actions::DecompressAction::DecompressAction(const actions::actionData& data) : actions::IAction(data) {
    this->action_type = data.type;
    this->data_txt = data.data;
    this->custom_action.insert(this->custom_action.end(), data.func_action.begin(), data.func_action.end());
}

// template <typename T>
// actions::IAction& actions::DecompressAction::execute(T data) {
//     std::cout << this->data << std::endl;
//     return *this;
// };

// template<>
actions::IAction& actions::DecompressAction::execute(std::vector<int>& data) {
    for (const auto& func : this->custom_action) {
        auto res = func(data);
        std::cout << this->data_txt << ": " << res << std::endl;
    }

    return *this;
}