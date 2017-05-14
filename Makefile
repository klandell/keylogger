CC=gcc
CFLAGS=-framework ApplicationServices
SOURCES=src/main.c src/logger.c
EXECUTABLE=keylogger


all: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)

clean:
	rm $(EXECUTABLE)
