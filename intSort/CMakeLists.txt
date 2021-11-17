cmake_minimum_required(VERSION 3.10.0)


project(intSort)


add_library(intArray 
    STATIC 
        intArray.cc    
)

target_include_directories(intArray
    PUBLIC
        "${PROJECT_SOURCE_DIR}"
)

add_library(sort 
    STATIC 
        intSort.cc    
)

target_include_directories(sort
    PUBLIC
        "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(sort intArray)

add_executable(main main.cc maxSubArray.cc)
target_link_libraries(main intArray sort)