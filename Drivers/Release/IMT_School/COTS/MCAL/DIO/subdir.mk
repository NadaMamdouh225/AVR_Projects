################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IMT_School/COTS/MCAL/DIO/DIO_prg.c 

OBJS += \
./IMT_School/COTS/MCAL/DIO/DIO_prg.o 

C_DEPS += \
./IMT_School/COTS/MCAL/DIO/DIO_prg.d 


# Each subdirectory must supply rules for building sources it contributes
IMT_School/COTS/MCAL/DIO/%.o: ../IMT_School/COTS/MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


