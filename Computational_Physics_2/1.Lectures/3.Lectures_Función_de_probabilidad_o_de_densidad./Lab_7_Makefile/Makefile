 # project name (generate executable with this name)
TARGET := out

# compiler
CC := gcc

# compiling flags
CFLAGS = -Wall 

# linking flags 
# LFLAGS   = -Wall

LIB_DIR=lib
INC_DIR=include
OBJ_DIR=share
SRC_DIR=src

SRCS:=$(SRC_DIR)/hello_make.c \
     $(LIB_DIR)/hello_func.c

OBJ:=$(SRCS:.c=*.o)

# OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)
# OBJS := $(LIBS:%=$(OBJ_DIR)/%.o)

_DEPS = hello_make.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hello_make.o hello_func.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Compile on src folder
$(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c $(OBJS) -o $@ $< $(CFLAGS)
	
# Compile on lib folder
$(LDIR)/%.o: %.c $(DEPS)
	$(CC) -c $(OBJS) -o $@ $< $(CFLAGS)
	
# Execute on share folder
hellomake: $(OBJ_DIR)/hello_make.o $(OBJ_DIR)/hello_func.o
	$(CC) -o $(TARGET) $(OBJ_DIR)/hello_make.o $(OBJ_DIR)/hello_func.o 

clean:
	rm -f *.o  out  .*  $(ODIR)/*.o
