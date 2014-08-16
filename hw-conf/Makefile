# Set project global variable to find out vhere is located porject directory
PROJECT_PWD = $(abspath ./../)

# Include project configuration
include ../Make.cfg


SOURCES = startup_stm32f429_439xx.s \
	  system_stm32f4xx.c \
	  syscalls.c

OUTPUT_DIR = obj

OBJ = $(patsubst %.c,$(OUTPUT_DIR)/%.o, $(SOURCES))
OBJ += $(patsubst %.s,$(OUTPUT_DIR)/%.o, $(SOURCES))

.PHONY: all clean

all: $(OUTPUT_DIR) $(OBJ)





$(OUTPUT_DIR):
	mkdir $@

clean:
	@$(ECHO) "$(COLOR_BLUE)Cleaning $(COLOR_RESET)"
	@$(RM) $(OUTPUT_DIR)

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



$(OUTPUT_DIR)/%.o : %.s
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
