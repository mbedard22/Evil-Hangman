CC = gcc
CFLAGS =  -g -Wall --std=c99
OBJECTS = main.o my_string.o generic_vector.o tree.o hangman.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

unit_test: my_string.o unit_test.o test_def.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o

unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -o unit_test.o -c unit_test.c

test_def.o: test_def.c
	$(CC) $(CFLAGS) -o test_def.o -c test_def.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: my_string.c 
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

generic_vector.o: generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o

tree.o: tree.c
	$(CC) $(CFLAGS) -c tree.c -o tree.o

hangman.o: hangman.c
	$(CC) $(CFLAGS) -c hangman.c -o hangman.o
clean: 
	rm string_driver $(OBJECTS) unit_test unit_test.o test_def.o


