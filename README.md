This C program accepts two integers from the user as command-line arguments (for
example, X and Y where X, Y are positive integers). The parent process will read X and Y from
the command line. The parent process will create three threads (i.e., thread_1, thread_2, and
thread_3). The parent process will write X and Y to input_array[0] and input_array[1],
respectively. The first thread (i.e., thread_1) will read X and Y from the input_array[] and perform
the summation, S = X + Y, and then the result S will be written to the input_array[2]. Next, the
second thread (i.e., thread_2) will read S from the input_array[2] and identify whether S is an even
or odd number. Also, thread_2 will read X and Y from input_array[] and then perform
multiplication M = X * Y and then write M to input_array[3]. Finally, the third thread (i.e.,
thread_3) will read M from the read_input_array[3] and reverse the number M.   

The output from the program should look like the following (for this example below, X and Y
represent 21 and 3, respectively):
1. parent (PID 280448) receives X = 21 and Y = 3 from the user
2. parent (PID 280448) writes X = 21 and Y = 3 to input_array[]
3. thread_1 (TID 140451159217984) reads X = 21 and Y = 3 from input_array[]
4. thread_1 (TID 140451159217984) writes X + Y = 24 to the input_array[2]
5. thread_2 (TID 140451159217985) reads 24 from the input_array[2]
6. thread_2 (TID 140451159217985) identifies that 24 is an even number
7. thread_2 (TID 140451159217985) reads X and Y from input_array[],writes X * Y = 63
to input_array[3]
8. thread_3 (TID 140451159217986) reads 63 from input_array[3]
9. thread_3 (TID 140451159217986) reverses the number 63 -> 36
    
In the above example, in line number 6, if S is NOT an even number, then the phrase “identifies
that S is an even number” above should read as “identifies that S is an odd number”. You must control the execution of the threads to follow the sequence order shown in the sample output
above. 

The implementation have the following functions:
1. void *sum(void *thread_id): This function is executed by thread_1. This function reads X
and Y from input_array[], performs summation i.e., S = X+Y, and writes S to
input_array[2].
2. void *even_odd(void *thread_id): This function is executed by thread_2. This function
reads S from the input_array[2] and identifies whether S is an even or odd number.
3. void *multiplication(void *thread_id): This function is executed by thread_2. This function
reads X and Y from input_array[], performs multiplication i.e., M = X*Y, and writes M to
input_array[3].
4. void *reverse_num(void *thread_id): This function is executed by thread 3. This function
reads M from input_array[3] and reverses the number M.
