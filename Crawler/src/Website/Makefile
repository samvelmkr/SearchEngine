CC = g++
CFLAGS = -Wall

BIN = ../../bin
OBJECT = $(patsubst %,$(BIN)/%, $(notdir Website.o))

GREEN = \033[1;32m
NC = \033[1;0m

.PHONY: all 

all: $(OBJECT)

$(BIN)/Website.o: Website.cpp Website.h 
	@echo "$(GREEN)Processing the Website module...$(NC)"
	$(CC) $(CFLAGS) -c Website.cpp -o $@