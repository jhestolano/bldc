PROJ_NAME=bldc

STM_DIR=../../STM32Cube_FW_F3_V1.10.0
STM_SRC+=$(STM_DIR)/Drivers/STM32F3xx_HAL_Driver/Src
RTOS_DIR=../../FreeRTOSv10.2.1
LIBS_DIR=../../libs

SRCS=hw/src/main.c
SRCS+=hw/src/stm32f3xx_it.c
SRCS+=hw/src/adc.c
SRCS+=hw/src/gpio.c
SRCS+=hw/src/pwm.c
SRCS+=hw/src/uart.c
SRCS+=hw/src/tmr.c
SRCS+=hw/src/enc.c
SRCS+=hw/src/apptask.c
SRCS+=app/src/app.c
SRCS+=app/src/mtrif.c
SRCS+=system/src/system_stm32f3xx.c
SRCS+=$(STM_DIR)/Drivers/CMSIS/Device/ST/STM32F3xx/Source/Templates/gcc/startup_stm32f302x8.s
SRCS+=$(STM_SRC)/stm32f3xx_hal_gpio.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_rcc.c
SRCS+=$(STM_SRC)/stm32f3xx_hal.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_cortex.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_adc.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_adc_ex.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_dma.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_rcc_ex.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_cortex.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_tim.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_tim_ex.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_uart.c
SRCS+=$(STM_SRC)/stm32f3xx_hal_uart_ex.c

# Generated code.
#SRCS+=mbd/codegen/ctrl_1khz_ert_rtw/ctrl_1khz.c
#SRCS+=mbd/codegen/ctrl_30khz_ert_rtw/ctrl_30khz.c
SRCS+=mbd/codegen/ctrl_ert_rtw/ctrl.c

# This is the location for printf.c file implementation from Embdedded Artistry.
SRCS+=$(LIBS_DIR)/printf/printf.c

# This is the location of port.c file.
SRCS+=$(RTOS_DIR)/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
SRCS+=$(RTOS_DIR)/FreeRTOS/Source/portable/MemMang/heap_2.c

# This is where the actual implementation of FreeRTOS is.
SRCS+=$(RTOS_DIR)/FreeRTOS/Source/tasks.c
SRCS+=$(RTOS_DIR)/FreeRTOS/Source/timers.c
SRCS+=$(RTOS_DIR)/FreeRTOS/Source/queue.c
SRCS+=$(RTOS_DIR)/FreeRTOS/Source/list.c


INC_DIRS=$(STM_DIR)/Drivers/CMSIS/Device/ST/STM32F3xx/Include
INC_DIRS+=$(STM_DIR)/Drivers/STM32F3xx_HAL_Driver/Inc
INC_DIRS+=$(STM_DIR)/Drivers/CMSIS/Include
INC_DIRS+=$(RTOS_DIR)/FreeRTOS/Source/include
INC_DIRS+=$(RTOS_DIR)/FreeRTOS/Source/portable/GCC/ARM_CM4F
INC_DIRS+=$(LIBS_DIR)/printf
INC_DIRS+=./system/inc
INC_DIRS+=./hw/inc
INC_DIRS+=./app/inc
INC_DIRS+=./mbd/codegen/ctrl_1khz_ert_rtw
INC_DIRS+=./mbd/codegen/ctrl_30khz_ert_rtw
INC_DIRS+=./mbd/codegen/ctrl_ert_rtw
INC_DIRS+=.

ST_LINK_DIR=~/opt/gnu-mcu-eclipse/stlink/build/Release

TOOLS_DIR=~/opt/gnu-mcu-eclipse/arm-none-eabi-gcc/bin
CC=$(TOOLS_DIR)/arm-none-eabi-gcc
OBJCOPY=$(TOOLS_DIR)/arm-none-eabi-objcopy
GDB=$(TOOLS_DIR)/arm-none-eabi-gdb
SZ=$(TOOLS_DIR)/arm-none-eabi-size

# Any compiler options you need to set
CFLAGS=-ggdb3
CFLAGS+=-Os
CFLAGS+=-Wall -Wextra -Warray-bounds
CFLAGS+=-mlittle-endian -mthumb -mcpu=cortex-m4
#CFLAGs+=mthumb-interwork
CFLAGS+=-mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS+=--specs=nosys.specs --specs=rdimon.specs
CFLAGS+=-ffunction-sections -fdata-sections -fno-math-errno

# Linker Files (all *.ld files)
LFLAGS=-Wl,-Map,$(PROJ_NAME).map -Wl,--gc-sections -T./linker/stm32f30_flash.ld

INCLUDE = $(addprefix -I,$(INC_DIRS))

DEFS=-DSTM32F302x8
#DEFS+=-D__DBG__
DEFS+=-D__SLOG__
DEFS+=-DENBL_MOTOR_IDENT

.PHONY: $(PROJ_NAME)
$(PROJ_NAME): $(PROJ_NAME).elf

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(INCLUDE) $(DEFS) $(CFLAGS) $(LFLAGS) $^ -o $@ 
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf   $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin
	$(SZ) $(PROJ_NAME).elf
    
clean:
	rm -f *.o $(PROJ_NAME).elf $(PROJ_NAME).hex $(PROJ_NAME).bin $(PROJ_NAME).map

flash: 
	$(ST_LINK_DIR)/st-flash write $(PROJ_NAME).bin 0x8000000

stlink:
	$(ST_LINK_DIR)/src/gdbserver/st-util

# before you start gdb, you must start st-util
.PHONY: debug
debug:
	$(GDB) ./$(PROJ_NAME).elf --command=cmd.gdb
