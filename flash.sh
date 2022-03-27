#!/bin/bash



openocd -f board/stm32f4discovery.cfg -c "program build/targets/jukebox_fw.elf verify reset exit"
