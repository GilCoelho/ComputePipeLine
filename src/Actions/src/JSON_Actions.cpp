#include<JSON_Actions.h>

#include<iostream>

actions::IAction& actions::JSONAction::execute() {
    std::cout << this->data << std::endl;
    return *this;
};