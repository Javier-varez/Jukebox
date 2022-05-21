# Jukebox

Jukebox player based on an STM32F411 Discovery board from ST Microelectronics.

## Getting started

First configure your terminal by running: 

```bash
source bootstrap.sh
```

Then just build the software with:

```bash
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain.cmake -DCMAKE_SYSTEM_NAME=Generic
make -C build
```

The output `elf` file will be under `build/Jukebox.elf`

Load the code to the target with: 

```bash
make -C build run
```
