#include "../src/dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* write_ten(void *arg) {
  
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


void write_fourty() {
    printf("Fourty\n");
    return;
}

void write_fifty() {
    printf("Fifty\n");
    return;
}

void write_sixsty() {
    printf("Sixty\n");
    return;
}

void write_ninety() {
    printf("Ninety\n");
    return;
}

int main(int argc, char **argv) {

    if(argc <= 1) {
        perror("Not Enough Argument\n");
        return -1;
    }

    if(0 == strcmp(argv[1], "1")) {

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
            pthread_create(threads + i, NULL, write_ten, data + i);
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
    }

    if(0 == strcmp(argv[1], "4")) {
        write_fourty();
    }

    if(0 == strcmp(argv[1], "5")) {
        write_fifty();
    }

    if(0 == strcmp(argv[1], "6")) {
        write_sixsty();
    }

    if(0 == strcmp(argv[1], "9")) {
        write_ninety();
    }

    return 0;
}