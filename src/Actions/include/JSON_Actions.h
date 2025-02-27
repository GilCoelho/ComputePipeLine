#ifndef JSON_ACTION_H
#define JSON_ACTION_H

#include <Actions.h>

namespace actions {
    class JSONAction : public IAction {
        public:
            JSONAction(const actions::actionData& data);
            template <typename T>
            IAction& execute(T data);

        private:
            ActionTypes type = ActionTypes::JSONDeserialize;
            std::string data = "I'm an JSON Action";
    };
}

#endif
