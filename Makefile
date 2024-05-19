
CC := gcc
CFLAGS := -Wall -Werror


ifdef CROSS_COMPILE
    CC := $(CROSS_COMPILE)gcc
endif


SRC := /home/tt20/aesd-assignment-2/finder-app/writer.c
OBJ := $(SRC:.c=.o)


all: writer


writer: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f writer $(OBJ)


.PHONY: all clean
