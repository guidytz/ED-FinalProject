# Name of the project
PROJ_NAME = contador
 
# .c files
C_SOURCE = $(wildcard ./src/*.c)
 
# .h files
H_SOURCE = $(wildcard ./inc/*.h)
 
# Object files
OBJ = $(subst .c,.o,$(subst src,obj,$(C_SOURCE)))
 
# Compiler and linker
CC = gcc

LIBS = -lm
 
# Flags for compiler
CC_FLAGS = -c         \
		   -I./inc	
 
# Command used at clean target
RM = rm -rf
 
#
# Compilation and linking
#
all: objFolder $(PROJ_NAME) clean
 
$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	@ $(CC) $^ -o $@ $(LIBS)
	@ echo 'Finished building binary: $@'
 
./obj/%.o: ./src/%.c ./inc/%.h
	@ echo 'Building target using GCC compiler: $<'
	@ $(CC) $< $(CC_FLAGS) -o $@
 
./obj/main.o: ./src/main.c $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	@ $(CC) $< $(CC_FLAGS) -o $@
 
objFolder:
	@ mkdir -p obj
 
clean:
	@ $(RM) ./obj/*.o *~
	@ rmdir obj

remove:
	@ echo 'Removing executable'
	@ rm $(PROJ_NAME)
 
.PHONY: all clean remove