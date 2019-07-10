################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/lcd.c \
../Src/main.c \
../Src/sensor.c \
../Src/servo.c \
../Src/stm32l0xx_it.c \
../Src/system_stm32l0xx.c \
../Src/tm_stm32f4_servo.c \
../Src/usart.c 

OBJS += \
./Src/gpio.o \
./Src/lcd.o \
./Src/main.o \
./Src/sensor.o \
./Src/servo.o \
./Src/stm32l0xx_it.o \
./Src/system_stm32l0xx.o \
./Src/tm_stm32f4_servo.o \
./Src/usart.o 

C_DEPS += \
./Src/gpio.d \
./Src/lcd.d \
./Src/main.d \
./Src/sensor.d \
./Src/servo.d \
./Src/stm32l0xx_it.d \
./Src/system_stm32l0xx.d \
./Src/tm_stm32f4_servo.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -mfloat-abi=soft -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DMSI_VALUE=2097000 -DHSI_VALUE=16000000 -DLSI_VALUE=37000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=0 -DINSTRUCTION_CACHE_ENABLE=1 -DDATA_CACHE_ENABLE=1 -D__weak=__attribute__((weak)) -D__packed=__attribute__((__packed__)) -DSTM32L053xx -I"C:/Users/ESIEA_I2_Etd/Desktop/radar/radar1/Inc" -I"C:/Users/ESIEA_I2_Etd/Desktop/radar/radar1/Drivers/STM32L0xx_HAL_Driver/Inc" -I"C:/Users/ESIEA_I2_Etd/Desktop/radar/radar1/Drivers/CMSIS/Device/ST/STM32L0xx/Include" -I"C:/Users/ESIEA_I2_Etd/Desktop/radar/radar1/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


