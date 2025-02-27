#include<JSON_Actions.h>

#include<iostream>

actions::JSONAction::JSONAction(const actions::actionData& data) : actions::IAction(data) {
    this->action_type = data.type;
    this->custom_action = data.func_action;
}

template <typename T>
actions::IAction& actions::JSONAction::execute(T data) {
    std::cout << this->data << std::endl;
    return *this;
};