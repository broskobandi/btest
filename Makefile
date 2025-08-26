INSTALL_DIR := /usr/local/include
INC := include/btest.h

all:

install:
	cp $(INC) $(INSTALL_DIR)

uninstall:
	rm $(addprefix $(INSTALL_DIR)/, $(notdir $(INC)))
