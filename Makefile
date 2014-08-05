# Set project global variable to find out vhere is located porject directory
PROJECT_PWD=$(abspath ./)

# Include project configuration
include Make.cfg


.PHONY:  all clean

all:
	@$(ECHO) "$(COLOR_BLUE)Colmpile ALL$(COLOR_RESET)"
	@$(MAKE) -C hw-conf all
	@$(MAKE) -C library-stm32f429 all
	@$(MAKE) -C src all

clean:
	@$(ECHO) "$(COLOR_BLUE)Cleaning ALL$(COLOR_RESET)"
	@$(MAKE) -C hw-conf clean
	@$(MAKE) -C library-stm32f429 clean
	@$(MAKE) -C src clean