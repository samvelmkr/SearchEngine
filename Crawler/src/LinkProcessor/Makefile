CC = g++
CFLAGS = -Wall `xml2-config --cflags`

BIN = ../../bin
OBJECT = $(patsubst %,$(BIN)/%, $(notdir LinkProcessor.o))

GREEN = \033[1;32m
NC = \033[1;0m

.PHONY: all 

all: $(OBJECT)

$(BIN)/LinkProcessor.o: LinkProcessor.cpp LinkProcessor.h ../HtmlDocument/HtmlDocument.h
	@echo "$(GREEN)Processing the LinkProcessor module...$(NC)"
	$(CC) $(CFLAGS) -c LinkProcessor.cpp -o $@