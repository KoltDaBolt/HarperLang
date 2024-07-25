# Weird Symbols
# '$@' represents the target filename
# '$^' represents the list of all prerequisites
# '$<' represents the first prerequisite

# Compiler Options
CC = gcc
CFLAGS = -Wall -Werror

# Directories
SRC_DIRS = . chunk memory debug value vm scanner compiler object table
OBJ_DIR = obj

# Source files
SRC_FILES = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

# Object files
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executable name
TARGET = harperlang

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# PHONY targets
.PHONY: all clean
