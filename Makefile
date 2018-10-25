# ED2-2018-2-TC2: Bin Packing Heuristic
#
# Author: Alan Herculano Diniz
#
# Project's makefile

CC		:= gcc
C_FLAGS := -Wall -g -O2 -lm

BIN		:= bin
SRC		:= src
INCLUDE	:= include

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= trab2.exe
else
EXECUTABLE	:= trab2
endif

all: $(EXECUTABLE)

clean:
	$(RM) $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

priority_queue.o: $(SRC)/priority_queue.c
	$(CC) -c $^ $(C_FLAGS)

main.o: $(SRC)/main.c
	$(CC) -c $^ $(C_FLAGS)

fit.o: $(SRC)/fit.c
	$(CC) -c $^ $(C_FLAGS)

bst.o: $(SRC)/bst.c
	$(CC) -c $^ $(C_FLAGS)

bstTest: $(SRC)/bstTest.c $(SRC)/bst.o
	$(CC) -o $@ $^ $(C_FLAGS)

pqTest: $(SRC)/pqTest.c $(SRC)/priority_queue.o
	$(CC) -o $@ $^ $(C_FLAGS)

$(EXECUTABLE): main.o priority_queue.o fit.o bst.o
	$(CC) -o $@ $^ $(C_FLAGS) && $(RM) *.o
