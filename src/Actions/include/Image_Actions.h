#ifndef IMAGE_ACTION_H
#define IMAGE_ACTION_H

#include <Actions.h>

namespace actions {
    class ImageAction : public IAction {
        public:
            ImageAction(const actions::actionData& data);
            ~ImageAction() = default;

            // template <typename T>
            // IAction& execute(T data);
            IAction& execute(std::vector<int>& data);

            void p() override {std::cout << data << std::endl;}

        private:
            ActionTypes type = ActionTypes::ImageDecode;
            std::string data = "I'm an Image Action";
    };
}

#endif
