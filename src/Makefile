# Set project global variable to find out vhere is located porject directory
PROJECT_PWD = $(abspath ./../)

# Include project configuration
include ../Make.cfg

SOURCES := $(call recursive_wildcard,./,*.c)

OUTPUT_DIR = obj

OBJ := $(patsubst %.c,$(OUTPUT_DIR)/%.o, $(SOURCES))

EXTERN_OBJ := ../hw-conf/obj/startup_stm32f429_439xx.o
EXTERN_OBJ += ../hw-conf/obj/system_stm32f4xx.o
EXTERN_OBJ += ../hw-conf/obj/syscalls.o

ELF_NAME := ../$(PROJ_NAME)
HEX_NAME := ../$(PROJ_NAME).hex
BIN_NAME := ../$(PROJ_NAME).bin

PROJECT_LIBS += -L$(PROJECT_PWD)/library-stm32f429/ -lstm32f429-periph



.PHONY: all clean

all: $(OUTPUT_DIR) $(ELF_NAME) $(HEX_NAME) $(BIN_NAME)

$(HEX_NAME) : $(ELF_NAME)
	@$(ECHO) -n "$(COLOR_BLUE)[HEX-GEN] $< -> $@ ... "
ifndef V
	@$(OBJCOPY) -O ihex $(ELF_NAME) $(HEX_NAME) 2> temp.log || touch temp.errors
else
	$(OBJCOPY) -O ihex $(ELF_NAME) $(HEX_NAME) 2> temp.log || touch temp.errors
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




$(BIN_NAME) : $(ELF_NAME)
	@$(ECHO) -n "$(COLOR_BLUE)[BIN-GEN] $< -> $@ ... "
ifndef V
	@$(OBJCOPY) -O binary $(ELF_NAME) $(BIN_NAME) 2> temp.log || touch temp.errors
else
	$(OBJCOPY) -O binary $(ELF_NAME) $(BIN_NAME) 2> temp.log || touch temp.errors
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




$(ELF_NAME): $(OBJ)
	@$(ECHO) -n "$(COLOR_BLUE)[LD] $< -> $@ ... "
ifndef V
	@$(CC) $(COMMON_FLAGS) $(OBJ) $(EXTERN_OBJ) -o $@ $(LDFLAGS) $(PROJECT_LIBS) 2> temp.log || touch temp.errors
else
	$(CC) $(COMMON_FLAGS) $(OBJ) $(EXTERN_OBJ) -o $@ $(LDFLAGS) $(PROJECT_LIBS) 2> temp.log || touch temp.errors
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
	@$(RM) $(ELF_NAME)
	@$(RM) $(BIN_NAME)
	@$(RM) $(HEX_NAME)

# Implicit rules
$(OUTPUT_DIR)/%.o : %.c
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
