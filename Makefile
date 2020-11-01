CC=gcc 
CFLAGS=-fsanitize=address -Wall -Werror -pthread 
TARGET=dynamic


.PHONY: clean

all: $(TARGET)

clean:
	rm -f $(TARGET) 
	rm -f *.o
	rm -f ./src/*.o
	rm -f ./test/*.o

#This will test the write ten percent
test1:
	time ./dynamic 1

#This will test the write 40%
test2:
	time ./dynamic 4

#This will test the write 50%
test3:
	time ./dynamic 5

#This will test the write 60%
test4:
	time ./dynamic 6

#This will test the write 90%
test5:
	time ./dynamic 9

#compiling

./test/test.o: ./test/test.c
	$(CC) -c $(CFLAGS) $^ -o $@

./src/dynamic_array.o: ./src/dynamic_array.c
	$(CC) -c $(CFLAGS) $^ -o $@

dynamic: ./src/dynamic_array.o ./test/test.o
	$(CC) $(CFLAGS) $^ -o $@	