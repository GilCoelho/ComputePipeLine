#include <iostream>
#include <vector>

#include <Actions.h>

actions::LoadTypes parse_uri(std::string& uri) {
    std::string scheme;

    // Find the position of "://"
    size_t pos = uri.find("://");
    if (pos != std::string::npos) {
        // Extract the scheme
        std::string scheme = uri.substr(0, pos);
    }

    return actions::s_mapStringToLoadTypes[scheme];
}

actions::IAction& actions::IAction::load(std::string& uri) {
    this->uri = uri;

    switch (parse_uri(uri))
    {
    case actions::LoadTypes::File_Loader:
        std::cout << "Loading a File" << std::endl;
        break;
    case actions::LoadTypes::URL_Loader:
        std::cout << "Loading a URL" << std::endl;
        break;
    case actions::LoadTypes::Bundle_Loader:
        std::cout << "Loading a Bundle" << std::endl;
        break;
    default:
    std::cout << "Loading type not present" << std::endl;
        break;
    }

    return *this;
}

actions::IAction& actions::IAction::execute() {
    std::cout << this->uri << std::endl;
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
