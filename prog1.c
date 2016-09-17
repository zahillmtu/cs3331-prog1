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
#include<string.h>

void printWrap(char buf[100]) {
    write(1, buf, strlen(buf));
}

void randomNums(int m) {
    char buf[100];

    sprintf(buf, "Random number has int %d\n", m);
    printWrap(buf);
}

void fibonacci(int n) {
    char buf[100];

    sprintf(buf, "fibonacci has int %d\n", n);
    printWrap(buf);
}

void needleSim(int r) {
    char buf[100];

    sprintf(buf, "needleSim has int %d\n", r);
    printWrap(buf);
}

void integration(int s) {
    char buf[100];

    sprintf(buf, "Integration has int %d\n", s);
    printWrap(buf);
}

int main(int argc, char* argv[]) {

    if (argc != 5) {
        printf("Incorrect number of arguments - Expecting 4, "
                "recieved %d\n", argc - 1);
        exit(1);
    }

    for (int i = 1; i < 5; i++) {
        printf("%d\n", atoi(argv[i]));
    }

    randomNums(atoi(argv[1]));
    fibonacci(atoi(argv[2]));
    needleSim(atoi(argv[3]));
    integration(atoi(argv[4]));
    exit(0);
}
