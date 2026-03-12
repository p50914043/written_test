set(PROJECT_NAME proto_test)
project(${PROJECT_NAME})

cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE PROTO_FILES "*.cc" "*.cpp")

add_executable(${PROJECT_NAME} 
proto_test.cpp
test.pb.cc
option.pb.cc

)


target_link_libraries(${PROJECT_NAME} PRIVATE
    protobuf
)

