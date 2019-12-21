cmake_minimum_required(VERSION 3.10)

# set the project name
project(AoC_2019)

# add the executable
add_executable(AoC_2019 source/main.cpp source/fuel_counter_upper/FuelCounterUpper.cpp include/fuel_counter_upper/FuelCounterUpper.h)

# add the include directory
target_include_directories(AoC_2019
                           PUBLIC
                               include/
                           )
