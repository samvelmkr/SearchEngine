TARGET = main

BIN = bin
SRC = src
SUBDIRS = $(SRC)/PageLoader $(SRC)/HtmlDocument $(SRC)/LinkProcessor $(SRC)/DocumentProcessor $(SRC)/crawler
 
YELLOW = \033[1;33m
NC = \033[1;0m

.PHONY: run clean help subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

run: $(SUBDIRS)
	@echo "$(YELLOW)Running...$(NC)"
	$(BIN)/$(TARGET)

clean:
	$(RM) $(BIN)/*.o $(BIN)/$(TARGET)

help: 
	@echo "subdirs: $(SUBDIRS)"
	@echo "src: $(SRC)"
	@echo "bin: $(BIN)"

#MODULES = subdir1 subdir2 subdir3
#
#all: 
#	for dir in $(MODULES); do \
#		@echo "processing folder $$dir"
#		(cd $$dir; $(MAKE) all); \
#	done