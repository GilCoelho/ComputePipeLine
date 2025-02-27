#include <gtest/gtest.h>

#include "loader.h"

TEST(ParseUriTest, FileUri) {
    std::string uri = "file://path/to/file";
    loader::LoadTypes type = loader::parse_uri(uri);

    EXPECT_EQ(type, loader::LoadTypes::File_Loader);
}

TEST(ParseUriTest, HttpUri) {
    std::string uri = "http://example.com";
    loader::LoadTypes type = loader::parse_uri(uri);

    EXPECT_EQ(type, loader::LoadTypes::URL_Loader);
}

TEST(ParseUriTest, HttpsUri) {
    std::string uri = "https://example.com";
    loader::LoadTypes type = loader::parse_uri(uri);

    EXPECT_EQ(type, loader::LoadTypes::URL_Loader);
}

TEST(ParseUriTest, BundleUri) {
    std::string uri = "bundle://path/to/bundle";
    loader::LoadTypes type = loader::parse_uri(uri);

    EXPECT_EQ(type, loader::LoadTypes::Bundle_Loader);
}

TEST(ParseUriTest, InvalidUri) {
    std::string uri = "invalid://path/to/resource";

    EXPECT_THROW(loader::parse_uri(uri), std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}