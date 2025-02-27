#ifndef DECOMPRESS_ACTION_H
#define DECOMPRESS_ACTION_H

#include <Actions.h>

namespace actions {
    class DecompressAction : public IAction {
        public:
            DecompressAction(const actions::actionData& data);
            template <typename T>
            IAction& execute(T data);

        private:
            ActionTypes type = ActionTypes::Decompression;
            std::string data = "I'm an Decompression Action";
    };
}

#endif