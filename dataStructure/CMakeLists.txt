cmake_minimum_required(VERSION 3.10.0)


project(HandWritingAlgorithm_DataStructure)


add_library(dataStructure
    STATIC 
        UIntArray.cc 
)

target_include_directories(dataStructure 
    PUBLIC
        ${PROJECT_SOURCE_DIR}
)

add_executable(test_UIntArray test_UIntArray.cc)
target_link_libraries(test_UIntArray dataStructure)