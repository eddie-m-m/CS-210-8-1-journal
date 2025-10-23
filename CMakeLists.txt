cmake_minimum_required(VERSION 4.1)

project(DepositSimulatorProject LANGUAGES CXX)

add_executable(deposit_simulator
    main.cpp
    DepositSimulator.cpp
    StaticReport.cpp
)

target_sources(deposit_simulator PRIVATE
    DepositSimulator.h
    StaticReport.h
    DepositFeatureSet.h
)

target_compile_features(deposit_simulator PRIVATE cxx_std_23)

if(MSVC)
    target_compile_options(deposit_simulator PRIVATE /W4)
else()
    target_compile_options(deposit_simulator PRIVATE -Wall -Wextra -pedantic)
endif()
