TARGET = main

CC = g++
CFLAGS = -Wall `xml2-config --cflags`
LIBS = -lcurl `xml2-config --libs`

BIN = ../../bin
OBJECTS = $(wildcard $(BIN)/*.o)
OBJECTS += $(patsubst %,$(BIN)/%, $(notdir Crawler.o))

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[1;0m

.PHONY: all 

all: $(BIN)/$(TARGET)
 
$(BIN)/$(TARGET): $(OBJECTS)
	@echo "$(RED)Linking...$(NC)"
	$(CC) $(OBJECTS) -o $@ $(LIBS)
	@echo "$(BLUE)Finished!$(NC)"


$(BIN)/Crawler.o: Crawler.cpp ../PageLoader/PageLoader.h ../HtmlDocument/HtmlDocument.h ../LinkProcessor/LinkProcessor.h ../DocumentProcessor/DocumentProcessor.h
	@echo "$(GREEN)Compiling...$(NC)"
	$(CC) $(CFLAGS) -c Crawler.cpp -o $@ 

 