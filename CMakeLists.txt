CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(van-gogh C)

SET(CMAKE_C_FLAGS "-Wall -Wextra -Wno-nullability-completeness")

ADD_EXECUTABLE(${PROJECT_NAME}
    src/main.c
)
