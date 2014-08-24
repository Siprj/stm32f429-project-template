# Set project global variable to find out where is locate project directory
PROJECT_PWD = $(abspath ./../)

# Query the default goal.
# If no goal is used the default one will be used (all).
ifeq ($(.DEFAULT_GOAL),)
$(warning no default goal is set, using all)
.DEFAULT_GOAL=all
endif

# Include project configuration
include ../Make.cfg

# Find all sources even if they are in complex directory structure.
SOURCES := $(call recursive_wildcard,./,*.c)

# Set output directory where all obj files generated from source files will be placed.
OUTPUT_DIR = obj

# Create list of object from source files. This is needed by implicit rule.
OBJ := $(patsubst %.c,$(OUTPUT_DIR)/%.o, $(SOURCES))

# Add external object from other parts of project. 
# Mainly hw files will be included into this lis.
EXTERN_OBJ := ../hw-conf/obj/startup_stm32f429_439xx.o
EXTERN_OBJ += ../hw-conf/obj/system_stm32f4xx.o
EXTERN_OBJ += ../hw-conf/obj/syscalls.o


# Set the names from PROJECT_NAME variable.
# Can be set to fit whatever you wish.
ELF_NAME := ../$(PROJ_NAME)
HEX_NAME := ../$(PROJ_NAME).hex
BIN_NAME := ../$(PROJ_NAME).bin

# There you can add libraries from some another project ....
# Is library is not in search path you can add library path in here to
PROJECT_LIBS += -L$(PROJECT_PWD)/library-stm32f429/ -lstm32f429-periph



# This construction is little bit tricky ;). It find all subdirectories which are 
# in sources paths. Directories are relative to src directory.
# Resul is for automatic creation of subdirectiories in OBJ directory.
OBJ_SUBDIRECTORIES = $(dir $(SOURCES))
OBJ_SUBDIRECTORIES := $(filter-out ./, $(OBJ_SUBDIRECTORIES))
OBJ_SUBDIRECTORIES := $(sort $(OBJ_SUBDIRECTORIES))
#OBJ_SUBDIRECTORIES := $(fullpath $(OBJ_SUBDIRECTORIES))

# Function for construction of dynamic targets which create subdirectory structure 
# meanchand in previous step.
define obj_subdirectories_constructor
$(1):
	@$(ECHO) "$(COLOR_BLUE)Creating suboutput directory: $(1) $(COLOR_RESET)"
	@mkdir -p $(1)
endef

# Creation of all subdirectories inside OBJ is depending on this two lines.
# First line create list of targets which responsible for creation of each directory.
# Second line create targets its self by using function mentioned above.
OBJ_SUBDIRECTORIES_TARGETS = $(foreach obj_subdir, $(OBJ_SUBDIRECTORIES), $(OUTPUT_DIR)/$(obj_subdir))
$(foreach obj_subdir, $(OBJ_SUBDIRECTORIES), $(eval $(call obj_subdirectories_constructor, $(OUTPUT_DIR)/$(obj_subdir))))





# no need to explain
.PHONY: all clean

# no need to explain
all: outputdir $(ELF_NAME) $(HEX_NAME) $(BIN_NAME)

# no need to explain
outputdir: $(OUTPUT_DIR) $(OBJ_SUBDIRECTORIES_TARGETS)


# HEX generating rule (ELF -> HEX)
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



# BIN generating rule (ELF -> BIN)
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



# Rule generating ELF file from object (OBJ -> ELF)
# ELF can be useb for debugging purposes by GDB
$(ELF_NAME): $(OBJ)
	@$(ECHO) -n "$(COLOR_BLUE)[LD] $(OBJ) -> $@ ... "
ifndef V
	@$(CC) $(COMMON_FLAGS) $(OBJ) $(EXTERN_OBJ) -o $@ $(PROJECT_LIBS)  $(LDFLAGS) 2> temp.log || touch temp.errors
else
	$(CC) $(COMMON_FLAGS) $(OBJ) $(EXTERN_OBJ) -o $@ $(PROJECT_LIBS) $(LDFLAGS) 2> temp.log || touch temp.errors
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


# Create basic directory where all artecat will be inserted.
$(OUTPUT_DIR):
	@$(ECHO) "$(COLOR_BLUE)Creating output directory: $@ $(COLOR_RESET)"
	@mkdir $@

# Clean remove all artefacts by removing output directory.
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
