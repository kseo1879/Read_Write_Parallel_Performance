#include "dynamic_array.h"

/**
 * =====THIS FUNCTION IS NOT THREAD SAFE=====
 * This function will initialize the struct dynamic_array and return it. 
 * It will also initialize the lock, and the structures variables.
 */
struct dynamic_array* dynamic_array_new(size_t initial_capacity) {

    //ERROR HANDLING
    if(0 >= initial_capacity) {
        perror("Initial size cannot be zero or less");
        return NULL;
    }

    //First create an array to return
    struct dynamic_array *array = (struct dynamic_array *)malloc(sizeof(struct dynamic_array));
   
    //Now it will initialize the fields of the structure
    pthread_rwlock_init(&(array->lock), NULL);
    array->capacity = initial_capacity;
    array->filled = 0;
    array->value_array = malloc(sizeof(void *) * initial_capacity);
    return array;
}

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
void dynamic_array_add(struct dynamic_array *ary, void *value) {

    //ERROR HANDLING
    if(NULL == ary || NULL == value) {
        perror("add function did not have the correct arguments\n");
        perror("The array and value should not be null\n");
        return;
    }

    //Before we add anything we need to first lock the whole list. 
    pthread_rwlock_wrlock(&(ary->lock));

    //Now we need to first see if the list is already full
    //If it's already full we will realloc the previous array to double sized array.
    if(ary->capacity <= ary->filled) {
        ary->capacity = 2 * ary->capacity;
        ary->value_array = (void *)realloc(ary->value_array, (sizeof(void *) * ary->capacity));
    }
    


    //We add the value to the list.
    (ary->value_array)[ary->filled] = value;
    ary->filled++;
    //Unlock the array lock after calling this function.
    pthread_rwlock_unlock(&(ary->lock));

    return;
}

/**
 * =====THIS FUNCTION IS THREAD SAFE=====
 * This is a simple read function and it will lock the lock with 'rdlock' function.
 * It will allow multiple thread the perform this when it's also the reading function.
 * 
 * It will return the value stored in the index of the array.
 */
void* dynamic_array_get(struct dynamic_array *ary, size_t index) {

    //ERROR HANDLING
    if(NULL == ary) {
        perror("get function did not get the correct argument\n");
        perror("Array should not be null\n");
        return NULL;
    }

    //First lock the list lock with readlock function. This will block 
    //other thread who will write but allow the ones that are trying to read. 
    pthread_rwlock_rdlock(&(ary->lock));

    if(index < 0 || index >= (ary->filled)) {
        perror("The index provided in get function is out of range\n");
        pthread_rwlock_unlock(&(ary->lock));
        return NULL;
    }

    //First read the value and store it into the local stack and then return
    void *value = (ary->value_array)[index];
    pthread_rwlock_unlock(&(ary->lock));

    return value;
}

/**
 * =====THIS FUNCTION IS THREAD SAFE=====
 * This will lock the the structure with wrlock function.
 * It will ensure that it only has only thread performing on the array and block all
 * the other threads from working on other function. 
 * 
 * It will remove the value stored from the array and return it. It is user responsibility to 
 * free the value if dynamically allocated values.  
 */
void* dynamic_array_remove(struct dynamic_array *ary, size_t index) {

    //ERROR HANDLING
    if(NULL == ary) {
        perror("Remove function did not get the correct argument\n");
        perror("The array and value should not be null\n");
        return NULL;
    }

    pthread_rwlock_wrlock(&(ary->lock));

    if(index < 0 || index >= (ary->filled)) {
        perror("The index provided in remove function is out of range\n");
        pthread_rwlock_unlock(&(ary->lock));
        return NULL;
    }

    void *value = (ary->value_array)[index];
    (ary->value_array)[index] = NULL;
    pthread_rwlock_unlock(&(ary->lock));

    return value;
}

/**
 * THIS FUNCTION IS NOT THREAD SAFE
 * This function will free all the dynamically allocated memories.
 * It will also destory the lock which was initialized from the neww function.
 * 
 * However it wont be freeing the memories of values. That would be user responsiblity.
 */
void dynamic_array_destory(struct dynamic_array *ary) {

    //ERROR HANDLING
    if(NULL == ary) {
        perror("Didn't provide the correct argument in destory function\n");
        return;
    }
    pthread_rwlock_destroy(&(ary->lock));
    free(ary->value_array);
    free(ary);

    return;
}

void *worker(void *arg) {

    struct data *data = (struct data *)arg;

    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &((data->data_array)[i]));
    }

    // for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
    //     i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
    //         dynamic_array_get(data->ary, i);
    // }

    return NULL;
}

int main() {
    printf("Test Begins\n");

    struct dynamic_array *ary = dynamic_array_new(TESTSIZE);
    
    double data_array[1000000];

    for(int i = 0; i < TESTSIZE; i++) {
        data_array[i] = i + 1;
    }

    struct data *data = malloc(sizeof(struct data) * N_THREADS);
    for(int i = 0; i < N_THREADS; i ++) {
        data[i].ary = ary;
        data[i].data_array = data_array;
        data[i].thread_index = i;
    }

    pthread_t threads[4];
    for(int i = 0; i < N_THREADS; i ++) {
        pthread_create(threads + i, NULL, worker, data + i);
    }

    for(int i = 0; i < N_THREADS; i ++) {
        pthread_join(threads[i], NULL);
    }
    printf("Test Begins\n");

    double sum = 0;
    for(int i = 0; i < TESTSIZE; i ++) {
        double *a = (double *)dynamic_array_get(ary, i);
        sum = sum + *a;
    }

    printf("EXPECTED : %f\n", (double)((TESTSIZE + 1) * (TESTSIZE/2)));
    printf("OBTAINED : %f\n", sum);
    
    free(data);
    dynamic_array_destory(ary);
    printf("Test Ends\n");
    return 0;
}