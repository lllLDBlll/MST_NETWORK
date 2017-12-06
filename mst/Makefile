# the compiler: gcc for C program, define as g++ for C++
CC = gcc
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = main grafo lista_enc no

all: $(TARGET)

$(TARGET): $(CC) $(CFLAGS) -o mast.ext $(TARGET).c

clean: $(RM) $(TARGET)