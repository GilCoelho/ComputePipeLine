#include <iostream>
#include <vector>

#include <Actions.h>

void Actions::sumVals(std::vector<int>& data) {
    int sum = 0;
    for (const auto& val : data) sum += val;
    std::cout << "Total sum: " << sum << std::endl;
}

void Actions::multiplyVals(std::vector<int>& data) {
    int mult = 1;
    for (const auto& val : data) mult = mult * val;
    std::cout << "Total Multiplication: " << mult << std::endl;
}

void Actions::printVals(std::vector<int>& data) {
    for (const auto& val : data) std::cout << val << " ";
    std::cout << std::endl;
}
