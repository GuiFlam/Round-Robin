CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iincludes
TARGET  = round_robin

SRCS    = main.c src/processus.c
OBJS    = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c includes/processus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
