#include <iostream>
#include <vector>

#include <Actions.h>

template <typename T>
actions::IAction& actions::IAction::execute(T data) {
    std::cout << this->data_txt << std::endl;
    return *this;
}

void actions::sumVals(std::vector<int>& data) {
    int sum = 0;
    for (const auto& val : data) sum += val;
    std::cout << "Total sum: " << sum << std::endl;
}

void actions::multiplyVals(std::vector<int>& data) {
    int mult = 1;
    for (const auto& val : data) mult = mult * val;
    std::cout << "Total Multiplication: " << mult << std::endl;
}

void actions::printVals(std::vector<int>& data) {
    for (const auto& val : data) std::cout << val << " ";
    std::cout << std::endl;
}
