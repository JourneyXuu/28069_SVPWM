################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../libraries/source/F2806x_CodeStartBranch.asm \
../libraries/source/F2806x_DBGIER.asm \
../libraries/source/F2806x_DisInt.asm \
../libraries/source/F2806x_usDelay.asm 

C_SRCS += \
../libraries/source/F2806x_Adc.c \
../libraries/source/F2806x_Comp.c \
../libraries/source/F2806x_CpuTimers.c \
../libraries/source/F2806x_DefaultIsr.c \
../libraries/source/F2806x_Dma.c \
../libraries/source/F2806x_ECan.c \
../libraries/source/F2806x_ECap.c \
../libraries/source/F2806x_EPwm.c \
../libraries/source/F2806x_EQep.c \
../libraries/source/F2806x_GlobalVariableDefs.c \
../libraries/source/F2806x_Gpio.c \
../libraries/source/F2806x_HRCap.c \
../libraries/source/F2806x_I2C.c \
../libraries/source/F2806x_Mcbsp.c \
../libraries/source/F2806x_OscComp.c \
../libraries/source/F2806x_PieCtrl.c \
../libraries/source/F2806x_PieVect.c \
../libraries/source/F2806x_Sci.c \
../libraries/source/F2806x_Spi.c \
../libraries/source/F2806x_SysCtrl.c \
../libraries/source/F2806x_TempSensorConv.c 

C_DEPS += \
./libraries/source/F2806x_Adc.d \
./libraries/source/F2806x_Comp.d \
./libraries/source/F2806x_CpuTimers.d \
./libraries/source/F2806x_DefaultIsr.d \
./libraries/source/F2806x_Dma.d \
./libraries/source/F2806x_ECan.d \
./libraries/source/F2806x_ECap.d \
./libraries/source/F2806x_EPwm.d \
./libraries/source/F2806x_EQep.d \
./libraries/source/F2806x_GlobalVariableDefs.d \
./libraries/source/F2806x_Gpio.d \
./libraries/source/F2806x_HRCap.d \
./libraries/source/F2806x_I2C.d \
./libraries/source/F2806x_Mcbsp.d \
./libraries/source/F2806x_OscComp.d \
./libraries/source/F2806x_PieCtrl.d \
./libraries/source/F2806x_PieVect.d \
./libraries/source/F2806x_Sci.d \
./libraries/source/F2806x_Spi.d \
./libraries/source/F2806x_SysCtrl.d \
./libraries/source/F2806x_TempSensorConv.d 

OBJS += \
./libraries/source/F2806x_Adc.obj \
./libraries/source/F2806x_CodeStartBranch.obj \
./libraries/source/F2806x_Comp.obj \
./libraries/source/F2806x_CpuTimers.obj \
./libraries/source/F2806x_DBGIER.obj \
./libraries/source/F2806x_DefaultIsr.obj \
./libraries/source/F2806x_DisInt.obj \
./libraries/source/F2806x_Dma.obj \
./libraries/source/F2806x_ECan.obj \
./libraries/source/F2806x_ECap.obj \
./libraries/source/F2806x_EPwm.obj \
./libraries/source/F2806x_EQep.obj \
./libraries/source/F2806x_GlobalVariableDefs.obj \
./libraries/source/F2806x_Gpio.obj \
./libraries/source/F2806x_HRCap.obj \
./libraries/source/F2806x_I2C.obj \
./libraries/source/F2806x_Mcbsp.obj \
./libraries/source/F2806x_OscComp.obj \
./libraries/source/F2806x_PieCtrl.obj \
./libraries/source/F2806x_PieVect.obj \
./libraries/source/F2806x_Sci.obj \
./libraries/source/F2806x_Spi.obj \
./libraries/source/F2806x_SysCtrl.obj \
./libraries/source/F2806x_TempSensorConv.obj \
./libraries/source/F2806x_usDelay.obj 

ASM_DEPS += \
./libraries/source/F2806x_CodeStartBranch.d \
./libraries/source/F2806x_DBGIER.d \
./libraries/source/F2806x_DisInt.d \
./libraries/source/F2806x_usDelay.d 

OBJS__QUOTED += \
"libraries\source\F2806x_Adc.obj" \
"libraries\source\F2806x_CodeStartBranch.obj" \
"libraries\source\F2806x_Comp.obj" \
"libraries\source\F2806x_CpuTimers.obj" \
"libraries\source\F2806x_DBGIER.obj" \
"libraries\source\F2806x_DefaultIsr.obj" \
"libraries\source\F2806x_DisInt.obj" \
"libraries\source\F2806x_Dma.obj" \
"libraries\source\F2806x_ECan.obj" \
"libraries\source\F2806x_ECap.obj" \
"libraries\source\F2806x_EPwm.obj" \
"libraries\source\F2806x_EQep.obj" \
"libraries\source\F2806x_GlobalVariableDefs.obj" \
"libraries\source\F2806x_Gpio.obj" \
"libraries\source\F2806x_HRCap.obj" \
"libraries\source\F2806x_I2C.obj" \
"libraries\source\F2806x_Mcbsp.obj" \
"libraries\source\F2806x_OscComp.obj" \
"libraries\source\F2806x_PieCtrl.obj" \
"libraries\source\F2806x_PieVect.obj" \
"libraries\source\F2806x_Sci.obj" \
"libraries\source\F2806x_Spi.obj" \
"libraries\source\F2806x_SysCtrl.obj" \
"libraries\source\F2806x_TempSensorConv.obj" \
"libraries\source\F2806x_usDelay.obj" 

C_DEPS__QUOTED += \
"libraries\source\F2806x_Adc.d" \
"libraries\source\F2806x_Comp.d" \
"libraries\source\F2806x_CpuTimers.d" \
"libraries\source\F2806x_DefaultIsr.d" \
"libraries\source\F2806x_Dma.d" \
"libraries\source\F2806x_ECan.d" \
"libraries\source\F2806x_ECap.d" \
"libraries\source\F2806x_EPwm.d" \
"libraries\source\F2806x_EQep.d" \
"libraries\source\F2806x_GlobalVariableDefs.d" \
"libraries\source\F2806x_Gpio.d" \
"libraries\source\F2806x_HRCap.d" \
"libraries\source\F2806x_I2C.d" \
"libraries\source\F2806x_Mcbsp.d" \
"libraries\source\F2806x_OscComp.d" \
"libraries\source\F2806x_PieCtrl.d" \
"libraries\source\F2806x_PieVect.d" \
"libraries\source\F2806x_Sci.d" \
"libraries\source\F2806x_Spi.d" \
"libraries\source\F2806x_SysCtrl.d" \
"libraries\source\F2806x_TempSensorConv.d" 

ASM_DEPS__QUOTED += \
"libraries\source\F2806x_CodeStartBranch.d" \
"libraries\source\F2806x_DBGIER.d" \
"libraries\source\F2806x_DisInt.d" \
"libraries\source\F2806x_usDelay.d" 

C_SRCS__QUOTED += \
"../libraries/source/F2806x_Adc.c" \
"../libraries/source/F2806x_Comp.c" \
"../libraries/source/F2806x_CpuTimers.c" \
"../libraries/source/F2806x_DefaultIsr.c" \
"../libraries/source/F2806x_Dma.c" \
"../libraries/source/F2806x_ECan.c" \
"../libraries/source/F2806x_ECap.c" \
"../libraries/source/F2806x_EPwm.c" \
"../libraries/source/F2806x_EQep.c" \
"../libraries/source/F2806x_GlobalVariableDefs.c" \
"../libraries/source/F2806x_Gpio.c" \
"../libraries/source/F2806x_HRCap.c" \
"../libraries/source/F2806x_I2C.c" \
"../libraries/source/F2806x_Mcbsp.c" \
"../libraries/source/F2806x_OscComp.c" \
"../libraries/source/F2806x_PieCtrl.c" \
"../libraries/source/F2806x_PieVect.c" \
"../libraries/source/F2806x_Sci.c" \
"../libraries/source/F2806x_Spi.c" \
"../libraries/source/F2806x_SysCtrl.c" \
"../libraries/source/F2806x_TempSensorConv.c" 

ASM_SRCS__QUOTED += \
"../libraries/source/F2806x_CodeStartBranch.asm" \
"../libraries/source/F2806x_DBGIER.asm" \
"../libraries/source/F2806x_DisInt.asm" \
"../libraries/source/F2806x_usDelay.asm" 


