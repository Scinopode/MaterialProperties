################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FPL.cpp \
../src/mpComponent.cpp \
../src/mpFunction.cpp \
../src/mpPhase.cpp 

OBJS += \
./src/FPL.o \
./src/mpComponent.o \
./src/mpFunction.o \
./src/mpPhase.o 

CPP_DEPS += \
./src/FPL.d \
./src/mpComponent.d \
./src/mpFunction.d \
./src/mpPhase.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


