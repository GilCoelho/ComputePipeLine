#include<Decompress_Actions.h>

#include<iostream>

actions::IAction& actions::DecompressAction::execute() {
    std::cout << this->data << std::endl;
    return *this;
};