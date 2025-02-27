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
    return actions::ActionFactory::instance().create(actions::ActionTypes::ImageDecode);
}

template<>
loader::actionPointer loader::loadUri<loader::LoadTypes::URL_Loader>(const std::string& uri) {
    std::cout << "Loading a URL: " << uri << std::endl;
    return actions::ActionFactory::instance().create(actions::ActionTypes::Decompression);
}

template<>
loader::actionPointer loader::loadUri<loader::LoadTypes::Bundle_Loader>(const std::string& uri) {
    std::cout << "Loading a Bundle: " << uri << std::endl;
    return actions::ActionFactory::instance().create(actions::ActionTypes::JSONDeserialize);
}

loader::loadUriFunc loader::buildUriObjs(const std::string& uri) {
    auto type = loader::parse_uri(uri);
    return loader::_mapLoadFuncs[type];
}
