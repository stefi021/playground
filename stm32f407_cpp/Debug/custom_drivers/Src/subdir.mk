################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../custom_drivers/Src/servo.cpp 

OBJS += \
./custom_drivers/Src/servo.o 

CPP_DEPS += \
./custom_drivers/Src/servo.d 


# Each subdirectory must supply rules for building sources it contributes
custom_drivers/Src/%.o custom_drivers/Src/%.su custom_drivers/Src/%.cyclo: ../custom_drivers/Src/%.cpp custom_drivers/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/taps/STM32CubeIDE/workspace_1.16.0/playground/stm32f407_cpp/custom_drivers/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-custom_drivers-2f-Src

clean-custom_drivers-2f-Src:
	-$(RM) ./custom_drivers/Src/servo.cyclo ./custom_drivers/Src/servo.d ./custom_drivers/Src/servo.o ./custom_drivers/Src/servo.su

.PHONY: clean-custom_drivers-2f-Src

