# ED2-2018-2-TC2: Bin Packing Heuristic
#
# Author: Alan Herculano Diniz
#
# Project's makefile

CC		:= gcc
C_FLAGS := -Wall -Wextra -g -O3

BIN		:= bin
SRC		:= src
INCLUDE	:= include

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= main
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	-$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	$(CC) $(C_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@