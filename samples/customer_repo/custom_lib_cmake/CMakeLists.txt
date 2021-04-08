# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)
#zephyr_include_directories(include)        #Add this line

#zephyr_library_include_directories(
  #include
#  src/drivers/spi
#)

#target_sources(app PRIVATE src/drivers/spi/multiply.c)  #Add this line
target_sources(app PRIVATE src/main.c)
