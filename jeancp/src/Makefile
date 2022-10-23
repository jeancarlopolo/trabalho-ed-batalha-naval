# Name of the project
objects = ted

# .c files
C_SOURCE=$(wildcard *.c)

# .h files
H_SOURCE=$(wildcard *.h)

# Object files
OBJ=$(C_SOURCE:.c=.o)

# Compiler
CC=gcc

# Aluno: Jean Carlo Polo
ALUNO = jeancp

# Flags for compiler
CC_FLAGS=-W         \
         -Wall      \
         -ansi      \
         -pedantic  \
	 -std=c99   \
	-fstack-protector-all \
		 -ggdb

LINKER_FLAGS = -lm

#
# Compilation and linking
#
all: $(objects)

$(objects): $(OBJ)
	$(CC) -o $@ $^ $(CC_FLAGS) $(LINKER_FLAGS)

%.o: %.c %.h
	$(CC) -o $@ $< -c $(CC_FLAGS) $(LINKER_FLAGS)

main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< -c $(CC_FLAGS)

clean:
	rm -rf *.o $(objects) *~

pack: $(objects)
	rm -f ../$(ALUNO).zip
	echo $(ALUNO)
	date >> .entrega
	cd ..; zip $(ALUNO).zip -r src/*.c src/*.h src/Makefile LEIA-ME.txt src/.entrega
