################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cda.c \
../list.c \
../lklist.c \
../main.c \
../stk.c 

OBJS += \
./cda.o \
./list.o \
./lklist.o \
./main.o \
./stk.o 

C_DEPS += \
./cda.d \
./list.d \
./lklist.d \
./main.d \
./stk.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


