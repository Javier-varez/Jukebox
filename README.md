# Jukebox

Jukebox player based on an STM32F411 Discovery board from ST Microelectronics.

## Getting started

First configure your terminal by running: 

```bash
source bootstrap.sh
```

Then just build the software with:

```bash
make -j$(nproc)
```

The output `elf` file will be under `build/targets/jukebox_fw.elf`
