CC = g++
CFLAGS = -Wall

BIN = ../../bin
OBJECT = $(patsubst %,$(BIN)/%, $(notdir DocumentRepos.o))

GREEN = \033[1;32m
NC = \033[1;0m

.PHONY: all 

all: $(OBJECT)

$(BIN)/DocumentRepos.o: DocumentRepos.cpp DocumentRepos.h 
	@echo "$(GREEN)Processing the DocumentRepos module...$(NC)"
	$(CC) $(CFLAGS) -c DocumentRepos.cpp -o $@