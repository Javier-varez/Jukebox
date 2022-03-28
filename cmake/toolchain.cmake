set(CMAKE_SYSTEM_NAME, Generic)
set(CMAKE_SYSTEM_PROCESSOR, arm)

set(triple thumbv7em-none-eabi)
set(ARM_TARGET_CONFIG "-mcpu=cortex-m4 -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -mthumb")
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER_TARGET ${triple})

set(arm_flags "${ARM_TARGET_CONFIG} -ffunction-sections -fdata-sections -specs=nosys.specs -specs=nano.specs")
set(arm_cxx_flags "${arm_flags} -fno-exceptions -fno-rtti")
set(CMAKE_C_FLAGS "${arm_flags}")
set(CMAKE_CXX_FLAGS "${arm_cxx_flags}")

link_libraries(-lnosys -lc_nano -lstdc++_nano)

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
