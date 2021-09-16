CC = g++
CFLAGS = -Wall `xml2-config --cflags`

BIN = ../../bin
OBJECT = $(patsubst %,$(BIN)/%, $(notdir DocumentProcessor.o))

GREEN = \033[1;32m
NC = \033[1;0m

.PHONY: all 

all: $(OBJECT)

$(BIN)/DocumentProcessor.o: DocumentProcessor.cpp DocumentProcessor.h ../HtmlDocument/HtmlDocument.h ../DocumentRepos/DocumentRepos.h
	@echo "$(GREEN)Processing the DocumentProcessor module...$(NC)"
	$(CC) $(CFLAGS) -c DocumentProcessor.cpp -o $@