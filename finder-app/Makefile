# Define the compiler and flags
CC := gcc
CFLAGS := -Wall -Werror

# Check if CROSS_COMPILE is specified, and if so, set the appropriate compiler
ifdef CROSS_COMPILE
    CC := $(CROSS_COMPILE)gcc
endif

# Define the source and object files
SRC := writer.c
OBJ := $(SRC:.c=.o)

# Default target to build the writer application
all: writer

# Rule to build the writer application
writer: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove the writer application and all .o files
clean:
	rm -f writer $(OBJ)

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean
