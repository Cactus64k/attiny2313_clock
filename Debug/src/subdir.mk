################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/timer.c \
../src/uart.c 

O_SRCS += \
../src/timer.o \
../src/uart.o 

OBJS += \
./src/main.o \
./src/timer.o \
./src/uart.o 

C_DEPS += \
./src/main.d \
./src/timer.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	avr-gcc -mmcu=attiny2313 -std=c99 -I/usr/lib/avr/include -Os -g3 -pedantic -Wall -Wextra -Wconversion -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


