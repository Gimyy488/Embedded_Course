################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Switch/subdir.mk
-include HAL/Led/subdir.mk
-include HAL/Lcd/subdir.mk
-include HAL/Keypad/subdir.mk
-include HAL/HexaDecoder/subdir.mk
-include HAL/Buzzer/subdir.mk
-include APP/TrafficLight/subdir.mk
-include APP/POV/subdir.mk
-include APP/LoginSystem/subdir.mk
-include APP/ClickGlow/subdir.mk
-include APP/Calculator/subdir.mk
-include APP/Animation/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Amit_AVR_Work.lss \

FLASH_IMAGE += \
Amit_AVR_Work.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Amit_AVR_Work.elf secondary-outputs

# Tool invocations
Amit_AVR_Work.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Amit_AVR_Work.map -mmcu=atmega32 -o "Amit_AVR_Work.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Amit_AVR_Work.lss: Amit_AVR_Work.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Amit_AVR_Work.elf  >"Amit_AVR_Work.lss"
	@echo 'Finished building: $@'
	@echo ' '

Amit_AVR_Work.hex: Amit_AVR_Work.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Amit_AVR_Work.elf  "Amit_AVR_Work.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Amit_AVR_Work.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Amit_AVR_Work.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Amit_AVR_Work.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
