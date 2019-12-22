cmake_minimum_required(VERSION 3.10)

# set the project name
project(AoC_2019)

# set the source aliases
set(SOURCES source/fuel_counter_upper/FuelCounterUpper.cpp include/fuel_counter_upper/FuelCounterUpper.h)
set(INPUT include/input/Day1.h)

# add the executable
add_executable(AoC_2019 source/main.cpp ${SOURCES} ${INPUT})

# add the include directory
target_include_directories(AoC_2019
                           PUBLIC
                               include/
                           )

