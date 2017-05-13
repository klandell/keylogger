CC=gcc
CFLAGS=-framework ApplicationServices
SOURCES=src/main.c src/logger.c
EXECUTABLE_DIR=out
EXECUTABLE=keylogger


all: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE_DIR)/$(EXECUTABLE)

clean:
	rm $(EXECUTABLE_DIR)/$(EXECUTABLE)
