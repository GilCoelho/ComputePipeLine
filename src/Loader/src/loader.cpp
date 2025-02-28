#include <loader.h>
#include <Actions_Factory.h>

loader::LoadTypes loader::parse_uri(const std::string& uri) {
    std::string scheme;

    // Find the position of "://"
    size_t pos = uri.find("://");
    if (pos != std::string::npos) {
        // Extract the scheme
        scheme = uri.substr(0, pos);
    }
    else {
        throw std::out_of_range("Invalid URI");
    }

    if(loader::_mapStringToLoadTypes.find(scheme) == loader::_mapStringToLoadTypes.end()) {
        throw std::out_of_range("Invalid URI");
    }

    return loader::_mapStringToLoadTypes[scheme];
}

template<>
loader::actionPointer loader::loadUri<loader::LoadTypes::File_Loader>(const std::string& uri) {
    std::cout << "Loading a File: " << uri << std::endl;

    // Process the File

    // Get data -> this step can be generated in a separate function
    actions::actionData data = {
        actions::ActionTypes::ImageDecode,
        "I'm an custom Action",
        {actions::sumVals<int>, actions::sumVals<int>}
    };

    return actions::ActionFactory::instance().create(actions::ActionTypes::ImageDecode, data);
}

template<>
loader::actionPointer loader::loadUri<loader::LoadTypes::URL_Loader>(const std::string& uri) {
    std::cout << "Loading a URL: " << uri << std::endl;

    // Process URL

    // Get data -> this step can be generated in a separate function
    actions::actionData data = {
        actions::ActionTypes::ImageDecode,
        "I'm an custom Action",
        {actions::multiplyVals<int>, actions::sumVals<int>}
    };

    return actions::ActionFactory::instance().create(actions::ActionTypes::Decompression, data);
}

template<>
loader::actionPointer loader::loadUri<loader::LoadTypes::Bundle_Loader>(const std::string& uri) {
    std::cout << "Loading a Bundle: " << uri << std::endl;

    // Process the Bundle

    // Get data -> this step can be generated in a separate function
    actions::actionData data = {
        actions::ActionTypes::ImageDecode,
        "I'm an custom Action",
        {actions::sumVals<int>, actions::sumVals<int>}
    };

    return actions::ActionFactory::instance().create(actions::ActionTypes::JSONDeserialize, data);
}

loader::loadUriFunc loader::buildUriObjs(const std::string& uri) {
    auto type = loader::parse_uri(uri);
    return loader::_mapLoadFuncs[type];
}
