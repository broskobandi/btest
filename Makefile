INSTALL_DIR := /usr/local/include
INC := include/test.h

all:

install:
	cp $(INC) $(INSTALL_DIR)

uninstall:
	rm $(addprefix $(INSTALL_DIR)/, $(notdir $(INC)))
