CC = g++
CFLAGS = -Wall `xml2-config --cflags`

BIN = ../../bin
OBJECT = $(patsubst %,$(BIN)/%, $(notdir HtmlDocument.o HtmlNodes.o HtmlNode.o))

GREEN = \033[1;32m
NC = \033[1;0m

.PHONY: all 

all: $(OBJECT)

$(BIN)/HtmlNode.o: HtmlNode.cpp HtmlNode.h
	@echo "$(GREEN)Processing the HtmlDocument module...$(NC)"
	$(CC) $(CFLAGS) -c HtmlNode.cpp -o $@

$(BIN)/HtmlNodes.o: HtmlNodes.cpp HtmlNodes.h HtmlNode.h
	$(CC) $(CFLAGS) -c HtmlNodes.cpp -o $@

$(BIN)/HtmlDocument.o: HtmlDocument.cpp HtmlDocument.h HtmlNodes.h HtmlNode.h
	$(CC) $(CFLAGS) -c HtmlDocument.cpp -o $@


