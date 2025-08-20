cmake_minimum_required(VERSION 3.21)
project(Pulse)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

# Main executable
add_executable(Pulse main.cpp)

# Test executable
add_executable(PulseTests tests.cpp)
add_test(NAME RunPulseTests COMMAND PulseTests)
