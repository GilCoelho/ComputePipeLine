#include<Image_Actions.h>

#include<iostream>

actions::IAction& actions::ImageAction::execute() {
    std::cout << this->data << std::endl;
    return *this;
};