cmake_minimum_required(VERSION 3.13)
# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(BarkBeetle)

pico_sdk_init()

add_executable(BarkBeetle)

target_sources(BarkBeetle PRIVATE
        main.c
        ../lib/rp2350_playground.c)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib")


target_compile_options(BarkBeetle PRIVATE -O0 -msoft-float -fno-fast-math)


target_link_libraries(BarkBeetle PRIVATE
        pico_stdlib
        hardware_pio
        hardware_i2c
        hardware_powman
        )

# Signing and hashing
pico_sign_binary(BarkBeetle ${CMAKE_CURRENT_SOURCE_DIR}/ec_private_key.pem)
pico_hash_binary(BarkBeetle)
# pico_set_otp_key_output_file(BarkBeetle ${CMAKE_CURRENT_LIST_DIR}/otp.json)

pico_add_extra_outputs(BarkBeetle)

# enable usb output, disable uart output
pico_enable_stdio_usb(BarkBeetle 1)
pico_enable_stdio_uart(BarkBeetle 0)