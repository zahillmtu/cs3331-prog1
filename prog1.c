/**
 * Zachary Hill
 * CS 3331
 *
 * This is an introductory program to the fork() and wait() functions
 * This program fork()s 4 children to run separate calculations.
 */

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {

    if (argc != 5) {
        printf("Incorrect number of arguments - Expecting 4, "
                "recieved %d\n", argc - 1);
        exit(1);
    }

    for (int i = 1; i < 5; i++) {
        printf("%d\n", atoi(argv[i]));
    }
}
