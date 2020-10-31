#ifndef DYNAMIC_H
#define DYNAMIC_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define TESTSIZE (1000000.0)
#define N_THREADS (4)

/**
 * This structure includes
 *      1.One read and write lock, which will help the functions be threadsafe.
 *      2.The capacity of the dynamic_array.
 *      3.The number of already filled data
 *      4.The dynamic array itself.
 */
struct dynamic_array {
    pthread_rwlock_t lock;
    size_t capacity;
    size_t filled;
    void **value_array; 
};

struct data {
    struct dynamic_array *ary;
    double *data_array; 
    int thread_index;
};

/**
 * =====THIS FUNCTION IS NOT THREAD SAFE=====
 * This function will initialize the struct dynamic_array and return it. 
 * It will also initialize the lock, and the structures variables.
 */
struct dynamic_array* dynamic_array_new(size_t initial_capacity);

/**
 * =====THIS FUNTION IS THREAD SAFE=====
 * This will lock the rwlock with 'wrlock' function. 
 * This will ensure that it will only allow one thread to operatre this 
 * write function. It will block other threads from writing.
 * 
 * It will add the values at the end of the array.
 * 
 * If the array it full, it will realloc the entire array 
 * (value array of struct dynamic array)
 */
void dynamic_array_add(struct dynamic_array *ary, void *value);

/**
 * =====THIS FUNCTION IS THREAD SAFE=====
 * This is a simple read function and it will lock the lock with 'rdlock' function.
 * It will allow multiple thread the perform this when it's also the reading function.
 * 
 * It will return the value stored in the index of the array.
 */
void* dynamic_array_get(struct dynamic_array *ary, size_t index);

/**
 * =====THIS FUNCTION IS THREAD SAFE=====
 * This will lock the the structure with wrlock function.
 * It will ensure that it only has only thread performing on the array and block all
 * the other threads from working on other function. 
 * 
 * It will remove the value stored from the array and return it. It is user responsibility to 
 * free the value if dynamically allocated values.  
 */
void* dynamic_array_remove(struct dynamic_array *ary, size_t index);

/**
 * THIS FUNCTION IS NOT THREAD SAFE
 * This function will free all the dynamically allocated memories.
 * It will also destory the lock which was initialized from the neww function.
 * 
 * However it wont be freeing the memories of values. That would be user responsiblity.
 */
void dynamic_array_destory(struct dynamic_array *ary);

#endif