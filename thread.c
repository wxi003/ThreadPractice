// This program accepts two positive integers X and Y as command-line arguments and creates 3 threads to do different jobs using X and Y.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int input_array[5];

// This function is executed by thread 3. This function reads M from input_array[3] and reverses the number M
void *reverse_num(void *thread_id)
{
	int rev_M = 0;
	int M = input_array[3];

	// The void pointer 'thread_id' is cast to an integer pointer
	// using '(int*)thread_id' Then, the value is dereferenced
	// with `*(int*)thread_id` to get the value at that memory location
	printf("thread_3 (TID %d) reads %d from input_array[3]\n", *(int *)thread_id, M);

	while (M > 0)
	{
		rev_M = rev_M * 10 + M % 10;
		M = M / 10;
	}

	printf("thread_3 (TID %d) reverses the number %d -> %d\n", *(int *)thread_id, input_array[3], rev_M);

	return NULL;
}

// This function is executed by thread_2. This function reads X and Y from input_array[], performs multiplication i.e., M = X*Y, and writes M to input_array[3].
void *multiplication(void *thread_id)
{
	int M = input_array[0] * input_array[1]; // M=X*Y
	input_array[3] = M;
	printf("thread_2 (TID %d) reads X and Y from input_array[], writes X * Y = %d to input_array[3]\n", *(int *)thread_id, M);
	return NULL;
}

// This function is executed by thread_2. This function reads S from the input_array[2] and identifies whether S is an even or odd number.
void *even_odd(void *thread_id)
{
	int S = input_array[2];

	printf("thread_2 (TID %d) reads %d from the input_array[2]\n", *(int *)thread_id, S);

	if (S % 2 == 0)
	{
		printf("thread_2 (TID %d) identifies that %d is an even number\n", *(int *)thread_id, S);
	}
	else
	{
		printf("thread_2 (TID %d) identifies that %d is an odd number\n", *(int *)thread_id, S);
	}

	multiplication(thread_id); // thread 2 also perform the multiplication function

	return NULL;
}

// This function is executed by thread_1. This function reads X and Y from input_array[], performs summation i.e., S = X+Y, and writes S to input_array[2].
void *sum(void *thread_id)
{
	int S = input_array[0] + input_array[1]; // S=X+Y
	input_array[2] = S;
	printf("thread_1 (TID %d) reads X = %d and Y = %d from input_array[]\n", *(int *)thread_id, input_array[0], input_array[1]);
	printf("thread_1 (TID %d) writes X + Y = %d to the input_array[2]\n", *(int *)thread_id, S);

	return NULL;
}

int main(int argc, char *argv[])
{
	input_array[0] = atoi(argv[1]); // put X in input_array[0]
	input_array[1] = atoi(argv[2]); // put Y in input_array[1]
	pthread_t thread_1, thread_2, thread_3;

	printf("\nparent (PID %d) receives X = %d and Y = %d from the user\n", getpid(), input_array[0], input_array[1]);
	printf("parent (PID %d) writes X = %d and Y = %d to input_array[]\n", getpid(), input_array[0], input_array[1]);

	pthread_create(&thread_1, NULL, sum, &thread_1);
	pthread_join(thread_1, NULL);

	pthread_create(&thread_2, NULL, even_odd, &thread_2);
	pthread_join(thread_2, NULL);

	pthread_create(&thread_3, NULL, reverse_num, &thread_3);
	pthread_join(thread_3, NULL);

	printf("\nAll threads terminated.\n");

	return 0;
}
