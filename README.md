# READ and WRITE lock in dynamic memory

This is a source code for making my own implementation of dynamic array using read and write lock

## How to use

### 1. First you need to build and link each object file:

You can simply type 'make' on your command line. 

```bash
make
```

### 2. 'After' you build your program here is the option:

#### There are total five different tests

```bash
make test1
```

- This is the result of the following test.
```bash
Test Begins for ten percent write
EXPECTED : 0
OBTAINED : 50000005000000.000000
Test Ends
22.68user 4.33system 0:08.92elapsed 302%CPU
```
- What does this mean?
Expected and obtained value exist to check if there was any miss usage resulting unintended data sharing. If they are the same it means that their is less percentace of the implementation being wrong of data array is wrong. 
It will also show how much time has ellapsed. 


##### The other options are "make test2", "make test3"....."make test5".

Each of the test corresponse to the persentage of read and write function. 

make test1 = 10% write, 90% read.

make test2 = 40% write, 60% read.

make test3 = 50% write, 50% read.

make test4 = 60% write, 40% read.

make test5 = 90% write, 10% read.


### 3. To clean the directory

```bash
make clean
```
