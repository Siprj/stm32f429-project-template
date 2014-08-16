# Set project global variable to find out vhere is located porject directory
PROJECT_PWD = $(abspath ./../)

# Include project configuration
include ../Make.cfg

SOURCES := $(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/misc.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma2d.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fmc.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_ltdc.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sai.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c \
	$(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.c \
	$(STM_COMMON)/Utilities/STM32F429I-Discovery/stm32f429i_discovery.c \
	$(STM_COMMON)/Utilities/STM32F429I-Discovery/stm32f429i_discovery_i2c_ee.c \
	$(STM_COMMON)/Utilities/STM32F429I-Discovery/stm32f429i_discovery_ioe.c \
	$(STM_COMMON)/Utilities/STM32F429I-Discovery/stm32f429i_discovery_l3gd20.c \
	$(STM_COMMON)/Utilities/STM32F429I-Discovery/stm32f429i_discovery_lcd.c \
	$(STM_COMMON)/Utilities/STM32F429I-Discovery/stm32f429i_discovery_sdram.c \
	$(STM_COMMON)/Utilities/Common/fonts.c \
	$(STM_COMMON)/Utilities/Common/lcd_log.c




OUTPUT_DIR = obj

OBJ := $(patsubst $(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/%.c,$(OUTPUT_DIR)/%.o, $(SOURCES))
OBJ += $(patsubst $(STM_COMMON)/Utilities/STM32F429I-Discovery/%.c,$(OUTPUT_DIR)/%.o, $(SOURCES))
OBJ += $(patsubst $(STM_COMMON)/Utilities/Common/%.c,$(OUTPUT_DIR)/%.o, $(SOURCES))

LIBRARY_NAME := libstm32f429-periph.a



.PHONY: all clean

all: $(OUTPUT_DIR) $(LIBRARY_NAME)

$(LIBRARY_NAME): $(OBJ)
	@$(ECHO) -n "$(COLOR_BLUE)[LD] $< -> $@ ... "
ifndef V
	@$(AR) rcs $@ $(OBJ) 2> temp.log || touch temp.errors
else
	$(AR) -crs $@ $(OBJ) 2> temp.log || touch temp.errors
endif
	@if [ -e temp.errors ]; then \
	    $(ECHO) "$(COLOR_RED)[ERRORS]:" 1>&2; \
	    cat temp.log 1>&2; \
	    $(ECHO) -n "$(COLOR_RESET)"; \
	    rm -f temp.log temp.errors; \
	    exit 1; \
	elif [ -s temp.log ]; then \
	    $(ECHO) "$(COLOR_YELLOW)[WARNINGS]:" 1>&2; \
	    cat temp.log 1>&2; \
	else \
	    $(ECHO) "$(COLOR_GREEN) [OK]"; \
	fi
	@$(ECHO) -n "$(COLOR_RESET)"
	@rm -f temp.log temp.errors


$(OUTPUT_DIR):
	@$(ECHO) "$(COLOR_BLUE)Creating output directory $(COLOR_RESET)"
	@mkdir $@

clean:
	@$(ECHO) "$(COLOR_BLUE)Cleaning $(COLOR_RESET)"
	@$(RM) $(LIBRARY_NAME)
	@$(RM) $(OUTPUT_DIR)

# Implicit rules
$(OUTPUT_DIR)/%.o : $(STM_COMMON)/Libraries/STM32F4xx_StdPeriph_Driver/src/%.c
	@$(ECHO) -n "$(COLOR_BLUE)[CC] $< -> $@ ... "
ifndef V
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 2> temp.log || touch temp.errors
else
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 2> temp.log || touch temp.errors
endif
	@if [ -e temp.errors ]; then \
	    $(ECHO) "$(COLOR_RED)[ERRORS]:" 1>&2; \
	    cat temp.log 1>&2; \
	    $(ECHO) -n "$(COLOR_RESET)"; \
	    rm -f temp.log temp.errors; \
	    exit 1; \
	elif [ -s temp.log ]; then \
	    $(ECHO) "$(COLOR_YELLOW)[WARNINGS]:" 1>&2; \
	    cat temp.log 1>&2; \
	else \
	    $(ECHO) "$(COLOR_GREEN) [OK]"; \
	fi
	@$(ECHO) -n "$(COLOR_RESET)"
	@rm -f temp.log temp.errors



# Implicit rules
$(OUTPUT_DIR)/%.o : $(STM_COMMON)/Utilities/STM32F429I-Discovery/%.c
	@$(ECHO) -n "$(COLOR_BLUE)[CC] $< -> $@ ... "
ifndef V
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 2> temp.log || touch temp.errors
else
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 2> temp.log || touch temp.errors
endif
	@if [ -e temp.errors ]; then \
	    $(ECHO) "$(COLOR_RED)[ERRORS]:" 1>&2; \
	    cat temp.log 1>&2; \
	    $(ECHO) -n "$(COLOR_RESET)"; \
	    rm -f temp.log temp.errors; \
	    exit 1; \
	elif [ -s temp.log ]; then \
	    $(ECHO) "$(COLOR_YELLOW)[WARNINGS]:" 1>&2; \
	    cat temp.log 1>&2; \
	else \
	    $(ECHO) "$(COLOR_GREEN) [OK]"; \
	fi
	@$(ECHO) -n "$(COLOR_RESET)"
	@rm -f temp.log temp.errors




# Implicit rules
$(OUTPUT_DIR)/%.o : $(STM_COMMON)/Utilities/Common/%.c
	@$(ECHO) -n "$(COLOR_BLUE)[CC] $< -> $@ ... "
ifndef V
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 2> temp.log || touch temp.errors
else
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 2> temp.log || touch temp.errors
endif
	@if [ -e temp.errors ]; then \
	    $(ECHO) "$(COLOR_RED)[ERRORS]:" 1>&2; \
	    cat temp.log 1>&2; \
	    $(ECHO) -n "$(COLOR_RESET)"; \
	    rm -f temp.log temp.errors; \
	    exit 1; \
	elif [ -s temp.log ]; then \
	    $(ECHO) "$(COLOR_YELLOW)[WARNINGS]:" 1>&2; \
	    cat temp.log 1>&2; \
	else \
	    $(ECHO) "$(COLOR_GREEN) [OK]"; \
	fi
	@$(ECHO) -n "$(COLOR_RESET)"
	@rm -f temp.log temp.errors
