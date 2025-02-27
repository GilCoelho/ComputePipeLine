#ifndef ACTION_H
#define ACTION_H

#include <map>
#include <vector>
#include <functional>

namespace actions {
    // LoadTypes enum
    enum LoadTypes
    {
        File_Loader,
        URL_Loader,
        Bundle_Loader,
    };

    static std::map<std::string, LoadTypes> s_mapStringToLoadTypes =
    {
        // parse_uri will remove the :// from the uri
        { "file", LoadTypes::File_Loader },
        { "http", LoadTypes::URL_Loader },
        { "https", LoadTypes::URL_Loader },
        { "bundle", LoadTypes::Bundle_Loader }
    };
    // ----------------------------

    // ActionTypes enum class
    enum class ActionTypes
    {
        ImageDecode,
        Decompression,
        JSONDeserialize,
    };
    // ----------------------------

    class IAction {
        public:
            IAction& load(std::string& uri);
            IAction& execute();

        private:
            std::string uri;
    };

    using Action = std::function<void(std::vector<int>&)>;

    void sumVals(std::vector<int>& data);
    void multiplyVals(std::vector<int>& data);
    void printVals(std::vector<int>& data);
}

#endif
