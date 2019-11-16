/*
 * Created Date: Saturday, November 16th 2019, 2:10:54 pm
 * Author: Guilherme Dytz dos Santos
 * -----
 * Last Modified: Saturday, November 16th 2019, 2:10:55 pm
 * Modified By: Guilherme Dytz dos Santos
 */
# Name of the project
PROJ_NAME = contador
 
# .c files
C_SOURCE = $(wildcard ./src/*.c)
 
# .h files
H_SOURCE = $(wildcard ./inc/*.h)
 
# Object files
OBJ = $(subst .c,.o,$(subst src,obj,$(C_SOURCE)))
 
# Compiler and linker
CC=gcc
 
# Flags for compiler
CC_FLAGS=-c         \
		 -I./inc
 
# Command used at clean target
RM = rm -rf
 
#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	@ $(CC) $^ -o $@ 
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
	@ echo 'Removing object files'
	@ $(RM) ./obj/*.o *~
	@ rmdir obj

remove:
	@ echo 'Removing executable'
	@ rm $(PROJ_NAME)

remove-all: clean remove
	@ echo 'All cleared'
 
.PHONY: all clean remove remove-all