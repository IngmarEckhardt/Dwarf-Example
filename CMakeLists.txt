cmake_minimum_required(VERSION 3.27)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_STANDARD 99)
set(MCU atmega328p)

# If you are using Atmel/Microchip Studio, create a new project and move these project files into this folder.
# Ensure that you include all the files and set "non-project" files to be visible.

set(NAME "Dwarf-Example")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 2)
project(${NAME} LANGUAGES C)

#Make sure you are using avr-gcc for this project. Add the folder containing avr-gcc to the PATH environment variable.
#Uncommenting this will work, but there are often better ways depending on your workflow/IDE.
# set(CMAKE_C_COMPILER avr-gcc)

# Toolchain path for AVR objcopy and size, change the path and file extensions to your environment
set(TOOLCHAIN_PATH "C:/Program Files/JetBrains/CLion 2023.3.4/bin/avr8-gnu-toolchain-win32_x86_64/bin/")
set(AVR_OBJCOPY "${TOOLCHAIN_PATH}avr-objcopy.exe")
set(AVR_SIZE "${TOOLCHAIN_PATH}avr-size.exe")

# compiler flags
set(CSTANDARD "-std=gnu99")
set(CDEBUG "-g -ggdb")
set(CTUNING "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections")
# use Optimization level -O2 if you have the space, it uses more program memory but is optimized for more speed
set(COPT "-Os -lm -frename-registers")
set(CMCU "-mmcu=${MCU}")
set(CWARN "-Wall -Wextra -Wstrict-prototypes -Wl,--gc-sections -Wl,--relax")
set(CFLAGS "${CMCU} ${COPT} ${CWARN} ${CSTANDARD} ${CTUNING} ${CDEBUG}")
set(CMAKE_C_FLAGS "${CFLAGS}")

set(INCL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(EXTERN_PATH "${CMAKE_CURRENT_SOURCE_DIR}/extern")

set(SRC_FILES
        #"${SRC_PATH}/example.c"
)

set(HEADER_FILES
        #"${INCL_PATH}/example.h"
)
include_directories(${INCL_PATH})

# add Dwarf-OS
set(BUILD_DWARFOS_AS_LIBRARY ON CACHE BOOL "Build DwarfOS as a library")
# We need to add these definitions here too, to turn on the compilation of the header
add_definitions(-D_TIME_T_DEFINED)
add_definitions(-DDWARF_TIME)
add_subdirectory(${EXTERN_PATH}/dwarf-os extern_build)


add_executable(${PROJECT_NAME} ${SRC_FILES} "${SRC_PATH}/standard_example.c")
target_include_directories(${PROJECT_NAME} PUBLIC ${INCL_PATH})
target_link_libraries(${PROJECT_NAME} DwarfOS)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")

# build a hex file if needed
add_custom_target(hex "${AVR_OBJCOPY}" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures
        "${PROJECT_NAME}.elf" "${PROJECT_NAME}.hex")
# display size of solution
add_custom_target(size "${AVR_SIZE}" "${PROJECT_NAME}.elf")

set(MODDED_FCT ${PROJECT_NAME}_modded)

add_executable(${MODDED_FCT} ${SRC_FILES} "${SRC_PATH}/modded_functions_example.c")
target_include_directories(${MODDED_FCT} PUBLIC ${INCL_PATH})
target_link_libraries(${MODDED_FCT} DwarfOS)
set_target_properties(${MODDED_FCT} PROPERTIES OUTPUT_NAME "${MODDED_FCT}.elf")


set(INPUTQUEUE_STDIN ${PROJECT_NAME}_with_stdin)

add_executable(${INPUTQUEUE_STDIN} ${SRC_FILES} "${SRC_PATH}/inputqueue_as_stdin_example.c")
target_include_directories(${INPUTQUEUE_STDIN} PUBLIC ${INCL_PATH})
target_link_libraries(${INPUTQUEUE_STDIN} DwarfOS)
set_target_properties(${INPUTQUEUE_STDIN} PROPERTIES OUTPUT_NAME "${INPUTQUEUE_STDIN}.elf")

set(SEND_LARGE_FILES_WITH_ATMEGA328 ${PROJECT_NAME}_large_strings)

add_executable(${SEND_LARGE_FILES_WITH_ATMEGA328} ${SRC_FILES} "${SRC_PATH}/sending_large_strings_with_AtMega328_example.c")
target_include_directories(${SEND_LARGE_FILES_WITH_ATMEGA328} PUBLIC ${INCL_PATH})
target_link_libraries(${SEND_LARGE_FILES_WITH_ATMEGA328} DwarfOS)
set_target_properties(${SEND_LARGE_FILES_WITH_ATMEGA328} PROPERTIES OUTPUT_NAME "${SEND_LARGE_FILES_WITH_ATMEGA328}.elf")

set_directory_properties(PROPERTIES
        ADDITIONAL_MAKE_CLEAN_FILES "${PROJECT_NAME}.hex;${PROJECT_NAME}.eeprom;${PROJECT_NAME}.lst")