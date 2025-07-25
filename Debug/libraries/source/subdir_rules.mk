################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
libraries/source/%.obj: ../libraries/source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/libraries/include" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/libraries/lib" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/libraries/source" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/App" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/bsp" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/Devices" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/Algorithm" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/Devices/IIC" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/Devices/OLED" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="libraries/source/$(basename $(<F)).d_raw" --obj_directory="libraries/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

libraries/source/%.obj: ../libraries/source/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/libraries/include" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/libraries/lib" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/libraries/source" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/App" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/bsp" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/Devices" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/Algorithm" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/Devices/IIC" --include_path="D:/A_Project/DSP_Project/workspace_v12/04_SVPWM/User/Devices/OLED" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="libraries/source/$(basename $(<F)).d_raw" --obj_directory="libraries/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


