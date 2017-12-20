################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ScannerST.cpp \
../SourceFile.cpp \
../Token.cpp 

OBJS += \
./ScannerST.o \
./SourceFile.o \
./Token.o 

CPP_DEPS += \
./ScannerST.d \
./SourceFile.d \
./Token.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/vagrant/Projects/SmartController/SmartCompiler/Util" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


