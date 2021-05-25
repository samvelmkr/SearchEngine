CC = g++
CFLAGS = -Wall

BIN = ../../bin
OBJECT = $(patsubst %,$(BIN)/%, $(notdir LoadResult.o PageLoader.o))

GREEN = \033[1;32m
NC = \033[1;0m

.PHONY: all 

all: $(OBJECT)

$(BIN)/LoadResult.o: LoadResult.cpp LoadResult.h
	@echo "$(GREEN)Processing the PageLoader module...$(NC)"
	$(CC) $(CFLAGS) -c LoadResult.cpp -o $@

$(BIN)/PageLoader.o: PageLoader.cpp PageLoader.h
	$(CC) $(CFLAGS) -c PageLoader.cpp -o $@


