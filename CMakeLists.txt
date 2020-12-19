cmake_minimum_required(VERSION 3.16)
project(learn C)

set(CMAKE_C_STANDARD 11)

add_executable(main main.c)
add_executable(farh-celcius farh-celcius.c)
add_executable(character_count character_count.c)
add_executable(longest_line longest_line.c)
add_executable(data_type_range data_type_range.c)
add_executable(data_type_range_bits data_type_range_bits.c)
add_executable(set_bits print_bits.c)