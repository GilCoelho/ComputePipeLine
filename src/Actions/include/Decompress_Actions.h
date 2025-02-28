#ifndef DECOMPRESS_ACTION_H
#define DECOMPRESS_ACTION_H

#include <Actions.h>

namespace actions {
    class DecompressAction : public IAction {
        public:
            DecompressAction(const actions::actionData& data);
            ~DecompressAction() = default;

            // template <typename T>
            // IAction& execute(T data);
            IAction& execute(std::vector<int>& data);

            void p() override {std::cout << data << std::endl;}

        private:
            ActionTypes type = ActionTypes::Decompression;
            std::string data = "I'm an Decompression Action";
    };
}

#endif