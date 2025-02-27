#ifndef IMAGE_ACTION_H
#define IMAGE_ACTION_H

#include <Actions.h>

namespace actions {
    class ImageAction : public IAction {
        public:
            ImageAction(const actions::actionData& data);
            template <typename T>
            IAction& execute(T data);

        private:
            ActionTypes type = ActionTypes::ImageDecode;
            std::string data = "I'm an Image Action";
    };
}

#endif
