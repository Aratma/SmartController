################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ScannerTest.cpp \
../ScannerTestMain.cpp 

OBJS += \
./ScannerTest.o \
./ScannerTestMain.o 

CPP_DEPS += \
./ScannerTest.d \
./ScannerTestMain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/vagrant/Projects/SmartController/SmartCompiler/Scanner" -I"/home/vagrant/Projects/SmartController/SmartCompiler/Util" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


