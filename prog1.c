/**
 * Zachary Hill
 * CS 3331
 *
 * This is an introductory program to the fork() and wait() functions
 * This program fork()s 4 children to run separate calculations.
 */

#include<math.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define PI 3.14159265358979323846

void printWrap(char buf[100]) {
    write(1, buf, strlen(buf));
}

void randomNums(int m) {
    char buf[100];

    sprintf(buf, "Random number has int %d\n", m);
    printWrap(buf);
}

long recursFib(long n) {

    if (n == 1 || n == 2) {
        return 1;
    }

    return recursFib(n - 1) + recursFib(n - 2);
}

void fibonacci(int n) {
    char buf[100];
    long result;

    sprintf(buf, "      Fibonacci Process Started\n");
    printWrap(buf);

    if (n < 1) {
        sprintf(buf, "Invalid number for fibonacci - %d\n", n);
        printWrap(buf);
        return;
    }


    result = recursFib((long)n);

    sprintf(buf, "      Input Number %d\n", n);
    printWrap(buf);
    sprintf(buf, "      Fibonacci Number f(%d) is %ld\n", n, result);
    printWrap(buf);
    sprintf(buf, "      Fibonacci Process Exits\n");
    printWrap(buf);
    //exit(0);
}

void needleSim(int r) {
    char buf[100];

    double dis, angle;
    double crossCount = 0;
    double result = 0;
    double finalRes = 0;

    sprintf(buf, "         Buffon's Needle Process Started\n");
    printWrap(buf);

    for (int i = 0; i < r; i++) {
        dis = ((double) rand())/RAND_MAX;                // random number [0, 1)
        angle = (((double) rand())/RAND_MAX) * 2 * PI; // random number [0, 2pi)

        result = dis + sin(angle);
        if (result < 0 || result > 1) {
            crossCount = crossCount + 1;
        }
    }

    finalRes = crossCount / r;

    sprintf(buf, "         Input Number %d\n", r);
    printWrap(buf);
    sprintf(buf, "         Estimated Probability is %.5f\n", finalRes);
    printWrap(buf);
    sprintf(buf, "         Buffon's Needle Process Exits\n");
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
