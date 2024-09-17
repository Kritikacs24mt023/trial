# Compiler and flags
CC = g++
CFLAGS=-O2 -m64 -msse3 -g -Wall -I$(HDR_DIR)
LDFLAGS=-m64 -msse3
LIBS =

# Directories
SRC_DIR = src
HDR_DIR = hdr
OBJ_DIR = obj
BIN_DIR = bin

# Files
OBJ_FILES = $(OBJ_DIR)/matvec.o $(OBJ_DIR)/timeutil.o
CPP_FILES = $(SRC_DIR)/matvec.cpp $(SRC_DIR)/timeutil.cpp
HEADER_FILES = $(HDR_DIR)/timeutil.h

# Targets
all: $(BIN_DIR)/matvec
	$(BIN_DIR)/matvec

$(BIN_DIR)/matvec: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/matvec.o: $(SRC_DIR)/matvec.cpp $(HEADER_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) $<

$(OBJ_DIR)/timeutil.o: $(SRC_DIR)/timeutil.cpp $(HEADER_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) $<

clean:
	$(RM) -r $(OBJ_DIR) $(BIN_DIR)/matvec

# Run the executable
run: $(BIN_DIR)/matvec
	./$(BIN_DIR)/matvec


.PHONY: clean all

