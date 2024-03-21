cmake_minimum_required(VERSION 3.27)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_STANDARD 99)
set(MCU atmega2560)

set(NAME "Textfile-Converter")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 3)
project(${NAME} LANGUAGES C)

option(TESTS "Build ${PROJECT_NAME} Tests with standard gcc" OFF)
option(MOCK_USER "Build ${PROJECT_NAME} with mocked user input" OFF)

set(TOOLCHAIN_PATH "C:/Program Files/JetBrains/CLion 2023.3.4/bin/avr8-gnu-toolchain-win32_x86_64/bin/")
set(AVR_OBJCOPY "${TOOLCHAIN_PATH}avr-objcopy.exe")
set(AVR_OBJDUMP "${TOOLCHAIN_PATH}avr-objdump.exe")
set(AVR_SIZE "${TOOLCHAIN_PATH}avr-size.exe")


set(CSTANDARD "-std=gnu99")


set(CDEBUG "-g -ggdb --coverage")

set(CFLAGS "${CSTANDARD} ${CDEBUG}")
set(CMAKE_C_FLAGS "${CFLAGS}")

set(INCL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(EXTERN_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../extern")





    set(TEST_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
    include_directories("${EXTERN_PATH}/dwarf-os")
    # adjust to your system
    set(CMAKE_SYSTEM_NAME Windows)





    # string_repository.c
    add_executable(${PROJECT_NAME}
            "${TEST_PATH}/textfile_generator.c"
            "${EXTERN_PATH}/dwarf-os/src/pgm_textfile_generator.c"
    )


    include(CTest)
    #    add_test(LongLocations ${PROJECT_NAME}_string_db_conversion)

