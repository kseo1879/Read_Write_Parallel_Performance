#include "../src/dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* write_ten(void *arg) {
  
    struct data *data = (struct data *)arg;
    //1
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }

    //2
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    //3
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    //4
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    //5
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    //6
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    //7
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //8
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //9
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //10
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    return NULL;
}

void* write_fourty(void *arg) {
    struct data *data = (struct data *)arg;
    //1
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }

    //2
    for(int i = (N_THREADS) * (TESTSIZE/N_THREADS);
        i < ((N_THREADS + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_remove(data->ary, i);
    }
    //3
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //4
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //5
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    //6
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    //7
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //8
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //9
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //10
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    return NULL;
}

void* write_fifty(void *arg) {
    struct data *data = (struct data *)arg;
    //1
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }

    //2
    for(int i = (N_THREADS) * (TESTSIZE/N_THREADS);
        i < ((N_THREADS +1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_remove(data->ary, i);
    }
    //3
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //4
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //5
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //6
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    //7
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //8
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //9
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //10
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    return NULL;
}

void* write_sixsty(void *arg) {
    struct data *data = (struct data *)arg;

    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }

    //2
    for(int i = (N_THREADS) * (TESTSIZE/N_THREADS);
        i < ((N_THREADS + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_remove(data->ary, i);
    }
    //3
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //4
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //5
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //6
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //7
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //8
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //9
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }

    //10
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    return NULL;
}

void* write_ninety(void *arg) {
    struct data *data = (struct data *)arg;

    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }

    //2
    for(int i = (N_THREADS) * (TESTSIZE/N_THREADS);
        i < ((N_THREADS + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_remove(data->ary, i);
    }
    //3
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //4
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //5
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //6
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }
    //7
    for(int i = (N_THREADS) * (TESTSIZE/N_THREADS);
        i < ((N_THREADS + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_remove(data->ary, i);
    }

    //8
    for(int i = (N_THREADS) * (TESTSIZE/N_THREADS);
        i < ((N_THREADS + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_remove(data->ary, i);
    }

    //9
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_add(data->ary, &(data->data_array[i]));
    }

    //10
    for(int i = (data->thread_index) * (TESTSIZE/N_THREADS);
        i < ((data->thread_index + 1) * (TESTSIZE/N_THREADS)); i ++) {
            dynamic_array_get(data->ary, i);
    }
    return NULL;
}

int main(int argc, char **argv) {

    if(argc <= 1) {
        perror("Not Enough Argument\n");
        return -1;
    }
    //====Initializing the data=====
    //Here we also add items to the array
    struct dynamic_array *ary = dynamic_array_new(TESTSIZE);
    
    double *array = malloc(sizeof(double) * TESTSIZE_INT * 9);

    for(int i = 0; i < TESTSIZE_INT; i++) {
        array[i] = i + 1;
    }

    struct data *data = malloc(sizeof(struct data) * N_THREADS);
    for(int i = 0; i < N_THREADS; i ++) {
        data[i].ary = ary;
        data[i].data_array = array;
        data[i].thread_index = i;
    }

    //First initialize the array.
    for(int i = 0; i < TESTSIZE_INT; i ++) {
        dynamic_array_add(ary, (array + i));
    }
    //====DONE Initializing the data=====

    if(0 == strcmp(argv[1], "1")) {

        printf("Test Begins for ten percent write\n");

        pthread_t threads[4];
        for(int i = 0; i < N_THREADS; i ++) {
            pthread_create(threads + i, NULL, write_ten, data + i);
        }

        for(int i = 0; i < N_THREADS; i ++) {
            pthread_join(threads[i], NULL);
        }

        double sum = 0;
        for(int i = 0; i < TESTSIZE; i ++) {
            double *a = (double *)dynamic_array_get(ary, i);
            if(NULL == a) {
                continue;
            }
            sum = sum + *a;
        }

        printf("EXPECTED : %f\n", (double)((TESTSIZE + 1) * (TESTSIZE/2)));
        printf("OBTAINED : %f\n", sum);
        
        free(data);
        dynamic_array_destory(ary);
        printf("Test Ends\n");
    } else if(0 == strcmp(argv[1], "4")) {

        printf("Test Begins for fourty percent write\n");

        pthread_t threads[4];
        for(int i = 0; i < N_THREADS; i ++) {
            pthread_create(threads + i, NULL, write_fourty, data + i);
        }

        for(int i = 0; i < N_THREADS; i ++) {
            pthread_join(threads[i], NULL);
        }

        double sum = 0;
        for(int i = 0; i < TESTSIZE; i ++) {
            double *a = (double *)dynamic_array_get(ary, i);
            if(NULL == a) {
                continue;
            }
            sum = sum + *a;
        }

        printf("EXPECTED : %f\n", (double)((TESTSIZE + 1) * (TESTSIZE/2)));
        printf("OBTAINED : %f\n", sum);
        
        free(data);
        dynamic_array_destory(ary);
        printf("Test Ends\n");
    } else if(0 == strcmp(argv[1], "5")) {
        printf("Test Begins for Fifty percent write\n");

        pthread_t threads[4];
        for(int i = 0; i < N_THREADS; i ++) {
            pthread_create(threads + i, NULL, write_fifty, data + i);
        }

        for(int i = 0; i < N_THREADS; i ++) {
            pthread_join(threads[i], NULL);
        }

        double sum = 0;
        for(int i = 0; i < TESTSIZE; i ++) {
            double *a = (double *)dynamic_array_get(ary, i);
            if(NULL == a) {
                continue;
            }
            sum = sum + *a;
        }

        printf("EXPECTED : %f\n", (double)((TESTSIZE + 1) * (TESTSIZE/2)));
        printf("OBTAINED : %f\n", sum);
        
        free(data);
        dynamic_array_destory(ary);
        printf("Test Ends\n");
    } else if(0 == strcmp(argv[1], "6")) {
        printf("Test Begins for Sixty percent write\n");

        pthread_t threads[4];
        for(int i = 0; i < N_THREADS; i ++) {
            pthread_create(threads + i, NULL, write_sixsty, data + i);
        }

        for(int i = 0; i < N_THREADS; i ++) {
            pthread_join(threads[i], NULL);
        }

        double sum = 0;
        for(int i = 0; i < TESTSIZE; i ++) {
            double *a = (double *)dynamic_array_get(ary, i);
            if(NULL == a) {
                continue;
            }
            sum = sum + *a;
        }

        printf("EXPECTED : %f\n", (double)((TESTSIZE + 1) * (TESTSIZE/2)));
        printf("OBTAINED : %f\n", sum);
        
        free(data);
        dynamic_array_destory(ary);
        printf("Test Ends\n");
    } else if(0 == strcmp(argv[1], "9")) {
          printf("Test Begins for Ninty percent write\n");

        pthread_t threads[4];
        for(int i = 0; i < N_THREADS; i ++) {
            pthread_create(threads + i, NULL, write_ninety, data + i);
        }

        for(int i = 0; i < N_THREADS; i ++) {
            pthread_join(threads[i], NULL);
        }

        double sum = 0;
        for(int i = 0; i < TESTSIZE; i ++) {
            double *a = (double *)dynamic_array_get(ary, i);
            if(NULL == a) {
                continue;
            }
            sum = sum + *a;
        }

        printf("EXPECTED : %f\n", (double)((TESTSIZE + 1) * (TESTSIZE/2)));
        printf("OBTAINED : %f\n", sum);
        
        free(data);
        dynamic_array_destory(ary);
        printf("Test Ends\n");
    }

    free(array);
    return 0;
}