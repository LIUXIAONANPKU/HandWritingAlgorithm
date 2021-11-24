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

add_executable(test_dataStructure test_dataStructure.cc)
target_link_libraries(test_dataStructure dataStructure)