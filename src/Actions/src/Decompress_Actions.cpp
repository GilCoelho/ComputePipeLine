#include<Decompress_Actions.h>

#include<iostream>

actions::DecompressAction::DecompressAction(const actions::actionData& data) : actions::IAction(data) {
    this->action_type = data.type;
    this->custom_action = data.func_action;
}

template <typename T>
actions::IAction& actions::DecompressAction::execute(T data) {
    std::cout << this->data << std::endl;
    return *this;
};