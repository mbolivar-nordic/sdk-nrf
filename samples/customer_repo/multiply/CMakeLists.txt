#target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/multiply.c)
#zephyr_library_named(spi_master)

#zephyr_include_directories(.)

zephyr_include_directories(.)
zephyr_library()
zephyr_library_sources(
  multiply.c
)