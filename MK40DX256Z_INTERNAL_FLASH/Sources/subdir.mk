################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/CameraInterface.c" \
"../Sources/Clock.c" \
"../Sources/SysTick.c" \
"../Sources/adc16.c" \
"../Sources/arm_cm4.c" \
"../Sources/initTSI.c" \
"../Sources/main.c" \
"../Sources/servo.c" \

C_SRCS += \
../Sources/CameraInterface.c \
../Sources/Clock.c \
../Sources/SysTick.c \
../Sources/adc16.c \
../Sources/arm_cm4.c \
../Sources/initTSI.c \
../Sources/main.c \
../Sources/servo.c \

OBJS += \
./Sources/CameraInterface.obj \
./Sources/Clock.obj \
./Sources/SysTick.obj \
./Sources/adc16.obj \
./Sources/arm_cm4.obj \
./Sources/initTSI.obj \
./Sources/main.obj \
./Sources/servo.obj \

OBJS_QUOTED += \
"./Sources/CameraInterface.obj" \
"./Sources/Clock.obj" \
"./Sources/SysTick.obj" \
"./Sources/adc16.obj" \
"./Sources/arm_cm4.obj" \
"./Sources/initTSI.obj" \
"./Sources/main.obj" \
"./Sources/servo.obj" \

C_DEPS += \
./Sources/CameraInterface.d \
./Sources/Clock.d \
./Sources/SysTick.d \
./Sources/adc16.d \
./Sources/arm_cm4.d \
./Sources/initTSI.d \
./Sources/main.d \
./Sources/servo.d \

C_DEPS_QUOTED += \
"./Sources/CameraInterface.d" \
"./Sources/Clock.d" \
"./Sources/SysTick.d" \
"./Sources/adc16.d" \
"./Sources/arm_cm4.d" \
"./Sources/initTSI.d" \
"./Sources/main.d" \
"./Sources/servo.d" \

OBJS_OS_FORMAT += \
./Sources/CameraInterface.obj \
./Sources/Clock.obj \
./Sources/SysTick.obj \
./Sources/adc16.obj \
./Sources/arm_cm4.obj \
./Sources/initTSI.obj \
./Sources/main.obj \
./Sources/servo.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/CameraInterface.obj: ../Sources/CameraInterface.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/CameraInterface.args" -o "Sources/CameraInterface.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Clock.obj: ../Sources/Clock.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Clock.args" -o "Sources/Clock.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SysTick.obj: ../Sources/SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/SysTick.args" -o "Sources/SysTick.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/adc16.obj: ../Sources/adc16.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/adc16.args" -o "Sources/adc16.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/arm_cm4.obj: ../Sources/arm_cm4.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/arm_cm4.args" -o "Sources/arm_cm4.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/initTSI.obj: ../Sources/initTSI.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/initTSI.args" -o "Sources/initTSI.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/main.args" -o "Sources/main.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/servo.obj: ../Sources/servo.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/servo.args" -o "Sources/servo.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


