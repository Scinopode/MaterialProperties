################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Substances/CarbonDioxide.cpp \
../src/Substances/CustomComponent.cpp \
../src/Substances/Water.cpp 

OBJS += \
./src/Substances/CarbonDioxide.o \
./src/Substances/CustomComponent.o \
./src/Substances/Water.o 

CPP_DEPS += \
./src/Substances/CarbonDioxide.d \
./src/Substances/CustomComponent.d \
./src/Substances/Water.d 


# Each subdirectory must supply rules for building sources it contributes
src/Substances/%.o: ../src/Substances/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


