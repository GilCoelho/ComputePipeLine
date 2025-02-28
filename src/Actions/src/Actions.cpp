#include <iostream>
#include <vector>

#include <Actions.h>

// template<>
actions::IAction& actions::IAction::execute(std::vector<int>& data) {
    for (const auto& func : this->custom_action) {
        auto res = func(data);
        std::cout << this->data_txt << ": " << res << std::endl;
    }

    return *this;
}
