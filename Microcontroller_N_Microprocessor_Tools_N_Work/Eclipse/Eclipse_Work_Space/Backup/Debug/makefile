################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TIMER/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include Keypad/subdir.mk
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
Backup.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Backup.elf secondary-outputs

# Tool invocations
Backup.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Backup.map -mmcu=atmega32 -o "Backup.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Backup.lss: Backup.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Backup.elf  >"Backup.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Backup.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Backup.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Backup.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
