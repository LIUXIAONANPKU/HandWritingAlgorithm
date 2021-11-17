cmake_minimum_required(VERSION 3.10.0)


project(c++IO)


add_executable(main main.cc func.cc)
target_include_directories(main
    PUBLIC
        "${PROJECT_SOURCE_DIR}"
)
