#include<Image_Actions.h>

#include<iostream>

actions::ImageAction::ImageAction(const actions::actionData& data) : actions::IAction(data) {
    this->action_type = data.type;
    this->custom_action = data.func_action;
}

template <typename T>
actions::IAction& actions::ImageAction::execute(T data) {
    std::cout << this->data << std::endl;
    return *this;
};
