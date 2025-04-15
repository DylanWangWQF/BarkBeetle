# Detect OS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    CC = clang
else
    CC = gcc
endif

CFLAGS = -std=c11 -Wall
LDFLAGS = -lm

SRCS = inf.c tree.c
OBJS = $(SRCS:.c=.o)
TARGET = inf

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o