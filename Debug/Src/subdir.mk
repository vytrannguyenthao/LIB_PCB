################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc_dma.c \
../Src/font.c \
../Src/gpio.c \
../Src/gpio_exti.c \
../Src/main.c \
../Src/rcc_config.c \
../Src/rtc.c \
../Src/rtc_app.c \
../Src/sharp96.c \
../Src/spi.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/tim.c 

OBJS += \
./Src/adc_dma.o \
./Src/font.o \
./Src/gpio.o \
./Src/gpio_exti.o \
./Src/main.o \
./Src/rcc_config.o \
./Src/rtc.o \
./Src/rtc_app.o \
./Src/sharp96.o \
./Src/spi.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/tim.o 

C_DEPS += \
./Src/adc_dma.d \
./Src/font.d \
./Src/gpio.d \
./Src/gpio_exti.d \
./Src/main.d \
./Src/rcc_config.d \
./Src/rtc.d \
./Src/rtc_app.d \
./Src/sharp96.d \
./Src/spi.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F103xB -c -I../Inc -I"D:/HOC_TAP/02_PIF/PIF_Courses/EmbeddedC/udemy_course/STM32BareMetal-Projects/00_test/chip_headers/CMSIS/Include" -I"D:/HOC_TAP/02_PIF/PIF_Courses/EmbeddedC/udemy_course/STM32BareMetal-Projects/00_test/chip_headers/CMSIS/Device/ST/STM32F1xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/adc_dma.cyclo ./Src/adc_dma.d ./Src/adc_dma.o ./Src/adc_dma.su ./Src/font.cyclo ./Src/font.d ./Src/font.o ./Src/font.su ./Src/gpio.cyclo ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/gpio_exti.cyclo ./Src/gpio_exti.d ./Src/gpio_exti.o ./Src/gpio_exti.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/rcc_config.cyclo ./Src/rcc_config.d ./Src/rcc_config.o ./Src/rcc_config.su ./Src/rtc.cyclo ./Src/rtc.d ./Src/rtc.o ./Src/rtc.su ./Src/rtc_app.cyclo ./Src/rtc_app.d ./Src/rtc_app.o ./Src/rtc_app.su ./Src/sharp96.cyclo ./Src/sharp96.d ./Src/sharp96.o ./Src/sharp96.su ./Src/spi.cyclo ./Src/spi.d ./Src/spi.o ./Src/spi.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/tim.cyclo ./Src/tim.d ./Src/tim.o ./Src/tim.su

.PHONY: clean-Src

