################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TIMER/TIMER_config.c \
../TIMER/TIMER_prog.c 

OBJS += \
./TIMER/TIMER_config.o \
./TIMER/TIMER_prog.o 

C_DEPS += \
./TIMER/TIMER_config.d \
./TIMER/TIMER_prog.d 


# Each subdirectory must supply rules for building sources it contributes
TIMER/%.o: ../TIMER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


