#include "Actions_Factory.h"

void actions::ActionFactory::registerAction(actions::ActionTypes actionType, ActionCreator creator) {
    creators[actionType] = std::move(creator);
}

std::unique_ptr<actions::IAction> actions::ActionFactory::create(actions::ActionTypes actionType, struct actions::actionData data) {
    auto it = creators.find(actionType);
    if (it != creators.end()) {
        return it->second(data);
    }

    throw std::runtime_error("Unknown action type");
}
