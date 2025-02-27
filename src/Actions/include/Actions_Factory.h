#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include "Actions.h"

#include "Image_Actions.h"
#include "Decompress_Actions.h"
#include "JSON_Actions.h"

#include <memory>
#include <unordered_map>
#include <functional>

namespace actions {

    class ActionFactory {
        public:
            using ActionCreator = std::function<std::unique_ptr<actions::IAction>()>;

            static ActionFactory& instance() {
                static ActionFactory factory;
                return factory;
            }

            void registerAction(actions::ActionTypes actionType, ActionCreator creator);
            std::unique_ptr<IAction> create(actions::ActionTypes actionType);

        private:
            std::unordered_map<actions::ActionTypes, ActionCreator> creators;

            // Private constructor for singleton pattern
            ActionFactory() {
                // Register available actions
                registerAction(actions::ActionTypes::ImageDecode, []() { return std::make_unique<ImageAction>(); });
                registerAction(actions::ActionTypes::Decompression, []() { return std::make_unique<DecompressAction>(); });
                registerAction(actions::ActionTypes::JSONDeserialize, []() { return std::make_unique<JSONAction>(); });
            }
        };
}

#endif
