# source files
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_rcc.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_dma.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_adc.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_gpio.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_adc_ex.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_dma_ex.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_pwr_ex.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_rcc_ex.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_flash.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_flash_ex.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_tim_ex.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_tim.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_cortex.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_spi.c
# C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_rng.c
C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_mdma.c
# C_SRC += $(DRIVERS)/Src/stm32h7xx_hal_dma2d.c


# optionals
C_SRC_UART = $(DRIVERS)/Src/stm32h7xx_hal_uart.c
C_SRC_UART += $(DRIVERS)/Src/stm32h7xx_hal_uart_ex.c
C_SRC_DAC = $(DRIVERS)/Src/stm32h7xx_hal_dac.c
C_SRC_DAC += $(DRIVERS)/Src/stm32h7xx_hal_dac_ex.c
C_SRC_CRC = $(DRIVERS)/Src/stm32h7xx_hal_crc.c
C_SRC_RTC = $(DRIVERS)/Src/stm32h7xx_hal_rtc.c
C_SRC_RTC += $(DRIVERS)/Src/stm32h7xx_hal_pwr.c
C_SRC_RTC += $(DRIVERS)/Src/stm32h7xx_hal_rtc_ex.c
C_SRC_IWDG = $(DRIVERS)/Src/stm32h7xx_hal_iwdg.c

# external SDRAM
C_SRC_SDRAM = $(DRIVERS)/Src/stm32h7xx_hal_sdram.c
C_SRC_SDRAM += $(DRIVERS)/Src/stm32h7xx_ll_fmc.c

# required by Daisy Seed
C_SRC_SAI = $(DRIVERS)/Src/stm32h7xx_hal_sai.c
C_SRC_SAI += $(DRIVERS)/Src/stm32h7xx_hal_sai_ex.c

C_SRC_QSPI += $(DRIVERS)/Src/stm32h7xx_hal_qspi.c
C_SRC_QSPI += $(OPENWARE)/Source/qspicontrol.c

C_SRC_SD = $(DRIVERS)/Src/stm32h7xx_hal_sd.c
C_SRC_SD += $(DRIVERS)/Src/stm32h7xx_hal_sd_ex.c
C_SRC_SD += $(DRIVERS)/Src/stm32h7xx_ll_sdmmc.c

### USB Device Library ###
C_SRC_USBD = $(DRIVERS)/Src/stm32h7xx_hal_pcd.c
C_SRC_USBD += $(DRIVERS)/Src/stm32h7xx_hal_pcd_ex.c
C_SRC_USBD += $(DRIVERS)/Src/stm32h7xx_ll_usb.c
C_SRC_USBD += $(USB_DEVICE_FILE)/Core/Src/usbd_core.c
C_SRC_USBD += $(USB_DEVICE_FILE)/Core/Src/usbd_ioreq.c
C_SRC_USBD += $(USB_DEVICE_FILE)/Core/Src/usbd_ctlreq.c

### USB Host Library ###
C_SRC_USBH = $(DRIVERS)/Src/stm32h7xx_hal_hcd.c
C_SRC_USBH += $(USB_HOST_FILE)/Core/Src/usbh_core.c
C_SRC_USBH += $(USB_HOST_FILE)/Core/Src/usbh_pipes.c
C_SRC_USBH += $(USB_HOST_FILE)/Core/Src/usbh_ioreq.c
C_SRC_USBH += $(USB_HOST_FILE)/Core/Src/usbh_ctlreq.c

### CMSIS DSP Library ####
C_SRC_DSP = $(DSPLIB)/FastMathFunctions/arm_sin_f32.c
C_SRC_DSP += $(DSPLIB)/FastMathFunctions/arm_cos_f32.c
C_SRC_DSP += $(DSPLIB)/CommonTables/arm_common_tables.c

C_SRC_DSP += $(DSPLIB)/TransformFunctions/arm_cfft_f32.c
C_SRC_DSP += $(DSPLIB)/TransformFunctions/arm_cfft_radix8_f32.c
C_SRC_DSP += $(DSPLIB)/TransformFunctions/arm_bitreversal.c
C_SRC_DSP += $(DSPLIB)/TransformFunctions/arm_rfft_fast_f32.c
C_SRC_DSP += $(DSPLIB)/TransformFunctions/arm_rfft_fast_init_f32.c
C_SRC_DSP += $(DSPLIB)/CommonTables/arm_const_structs.c

# C_SRC += $(DSPLIB)/FilteringFunctions/arm_biquad_cascade_df1_init_f32.c
# C_SRC += $(DSPLIB)/FilteringFunctions/arm_biquad_cascade_df1_f32.c

# C_SRC += $(DSPLIB)/SupportFunctions/arm_copy_f32.c
# C_SRC += $(DSPLIB)/SupportFunctions/arm_float_to_q31.c
# C_SRC += $(DSPLIB)/SupportFunctions/arm_q31_to_float.c
# C_SRC += $(DSPLIB)/SupportFunctions/arm_float_to_q15.c
# C_SRC += $(DSPLIB)/SupportFunctions/arm_q15_to_float.c

# C_SRC += $(DSPLIB)/FastMathFunctions/arm_sin_f32.c
# C_SRC += $(DSPLIB)/FastMathFunctions/arm_cos_f32.c
# C_SRC += $(DSPLIB)/FilteringFunctions/arm_biquad_cascade_df1_f32.c
# C_SRC += $(DSPLIB)/FilteringFunctions/arm_biquad_cascade_df1_init_f32.c
# C_SRC += $(DSPLIB)/SupportFunctions/arm_float_to_q31.c
# C_SRC += $(DSPLIB)/SupportFunctions/arm_q31_to_float.c
# C_SRC += $(DSPLIB)/SupportFunctions/arm_float_to_q15.c
# C_SRC += $(DSPLIB)/SupportFunctions/arm_q15_to_float.c

### FreeRTOS ###
C_SRC_OS = $(FREERTOS_DIR)/CMSIS_RTOS/cmsis_os.c
# C_SRC_OS = $(FREERTOS_DIR)/CMSIS_RTOS/cmsis_os2.c
# C_SRC_OS += $(FREERTOS_DIR)/portable/GCC/ARM_CM7/r0p1/port.c
C_SRC_OS += $(FREERTOS_DIR)/portable/GCC/ARM_CM4F/port.c
C_SRC_OS += $(FREERTOS_DIR)/tasks.c
C_SRC_OS += $(FREERTOS_DIR)/timers.c
C_SRC_OS += $(FREERTOS_DIR)/queue.c
C_SRC_OS += $(FREERTOS_DIR)/list.c
C_SRC_OS += $(FREERTOS_DIR)/croutine.c
C_SRC_OS += $(FREERTOS_DIR)/portable/MemMang/heap_4.c

C_SRC_FAT = $(FATFS_DIR)/diskio.c
C_SRC_FAT += $(FATFS_DIR)/ff.c
C_SRC_FAT += $(FATFS_DIR)/ff_gen_drv.c
# C_SRC_FAT += $(FATFS_DIR)/option/cc932.c
# C_SRC_FAT += $(FATFS_DIR)/option/cc936.c
# C_SRC_FAT += $(FATFS_DIR)/option/cc949.c
# C_SRC_FAT += $(FATFS_DIR)/option/ccsbcs.c
C_SRC_FAT += $(FATFS_DIR)/option/syscall.c
C_SRC_FAT += $(FATFS_DIR)/option/unicode.c
