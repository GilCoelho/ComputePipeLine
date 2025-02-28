#ifndef JSON_ACTION_H
#define JSON_ACTION_H

#include <Actions.h>

namespace actions {
    class JSONAction : public IAction {
        public:
            JSONAction(const actions::actionData& data);
            ~JSONAction() = default;

            // template <typename T>
            // IAction& execute(T data);
            IAction& execute(std::vector<int>& data);

            void p() override {std::cout << data << std::endl;}

        private:
            ActionTypes type = ActionTypes::JSONDeserialize;
            std::string data = "I'm an JSON Action";
    };
}

#endif
