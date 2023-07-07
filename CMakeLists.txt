cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(sevendisplay C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(sevendisplay
	main.c
)

pico_enable_stdio_usb(sevendisplay 1)
pico_enable_stdio_uart(sevendisplay 1)

pico_add_extra_outputs(sevendisplay)

target_link_libraries(sevendisplay pico_stdlib)
