CC = g++
CFLAGS = -Wall 

BIN = ../../bin
OBJECT = $(patsubst %,$(BIN)/%, $(notdir LinkEntry.o LinkRepository.o))

GREEN = \033[1;32m
NC = \033[1;0m

.PHONY: all 

all: $(OBJECT)

$(BIN)/LinkEntry.o: LinkStatus.h LinkEntry.h LinkEntry.cpp
	@echo "$(GREEN)Processing the LinkRepository module...$(NC)"
	$(CC) $(CFLAGS) -c LinkEntry.cpp -o $@

$(BIN)/LinkRepository.o: LinkRepository.cpp LinkRepository.h LinkEntry.h
	$(CC) $(CFLAGS) -c LinkRepository.cpp -o $@
