CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iincludes
TARGET  = round_robin

SRCS    = main.c src/processus.c

all: $(TARGET)

$(TARGET): $(SRCS) includes/processus.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
