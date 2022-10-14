################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/src/stm32f4-hal/subdir.mk
-include system/src/newlib/subdir.mk
-include system/src/diag/subdir.mk
-include system/src/cortexm/subdir.mk
-include system/src/cmsis/subdir.mk
-include src/ARM_COTS/RTOS/subdir.mk
-include src/ARM_COTS/MCAL/SysTick/subdir.mk
-include src/ARM_COTS/MCAL/SPI/subdir.mk
-include src/ARM_COTS/MCAL/RCC/subdir.mk
-include src/ARM_COTS/MCAL/NVIC/subdir.mk
-include src/ARM_COTS/MCAL/GPIO/subdir.mk
-include src/ARM_COTS/MCAL/EXTI/subdir.mk
-include src/ARM_COTS/HAL/TFT/subdir.mk
-include src/ARM_COTS/HAL/LED_Matrix/subdir.mk
-include src/ARM_COTS/HAL/IR/subdir.mk
-include src/ARM_COTS/HAL/DAC/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
STM32F401CCU6_Drivers.hex \

SECONDARY_SIZE += \
STM32F401CCU6_Drivers.siz \


# All Target
all: STM32F401CCU6_Drivers.elf secondary-outputs

# Tool invocations
STM32F401CCU6_Drivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM GNU C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -T mem.ld -T libs.ld -T sections.ld -nostartfiles -Xlinker --gc-sections -L"../ldscripts" -Wl,-Map,"STM32F401CCU6_Drivers.map" --specs=nano.specs -o "STM32F401CCU6_Drivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

STM32F401CCU6_Drivers.hex: STM32F401CCU6_Drivers.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "STM32F401CCU6_Drivers.elf"  "STM32F401CCU6_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM32F401CCU6_Drivers.siz: STM32F401CCU6_Drivers.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "STM32F401CCU6_Drivers.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) STM32F401CCU6_Drivers.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
