#ifndef LOADER_H
#define LOADER_H

#include <functional>
#include <iostream>
#include <string>
#include <memory>
#include <map>

#include <Actions.h>

namespace loader {
    enum LoadTypes
    {
        File_Loader,
        URL_Loader,
        Bundle_Loader,
    };

    static std::map<std::string, LoadTypes> _mapStringToLoadTypes =
    {
        // parse_uri will remove the :// from the uri
        { "file", LoadTypes::File_Loader },
        { "http", LoadTypes::URL_Loader },
        { "https", LoadTypes::URL_Loader },
        { "bundle", LoadTypes::Bundle_Loader }
    };

    LoadTypes parse_uri(const std::string& uri);

    using loadUriFunc = std::function<std::shared_ptr<actions::IAction>(const std::string&)>;
    using actionPointer = std::shared_ptr<actions::IAction>;

    template<LoadTypes T>
    actionPointer loadUri(const std::string& uri);

    // Declare template specializations
    template<>
    actionPointer loadUri<LoadTypes::File_Loader>(const std::string& uri);

    template<>
    actionPointer loadUri<LoadTypes::URL_Loader>(const std::string& uri);

    template<>
    actionPointer loadUri<LoadTypes::Bundle_Loader>(const std::string& uri);

    static std::map<LoadTypes, loadUriFunc> _mapLoadFuncs = {
        { LoadTypes::File_Loader, loadUri<LoadTypes::File_Loader> },
        { LoadTypes::URL_Loader, loadUri<LoadTypes::URL_Loader> },
        { LoadTypes::Bundle_Loader, loadUri<LoadTypes::Bundle_Loader> }
    };

    loadUriFunc buildUriObjs(const std::string& uri);
}

#endif
