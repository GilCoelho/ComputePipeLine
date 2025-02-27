#ifndef IMAGE_ACTION_H
#define IMAGE_ACTION_H

#include <Actions.h>

namespace actions {
    class ImageAction : public IAction {
        public:
            IAction& execute();

        private:
            ActionTypes type = ActionTypes::ImageDecode;
            std::string data = "I'm an Image Action";
    };
}

#endif
