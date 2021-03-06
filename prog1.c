// -----------------------------------------------------------
// NAME : Zachary Hill                         User ID: zahill
// DUE DATE : 09/23/2016
// PROGRAM ASSIGNMENT #1
// FILE NAME : prog1.c
// PROGRAM PURPOSE :
//    This is an introductory program to the wait()
//    and fork() functions. The program must fork()
//    four child and run separate calculations in each
// -----------------------------------------------------------
#include<math.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define PI 3.14159265358979323846

// -----------------------------------------------------------
// FUNCTION printWrap :
//    A wrapper method for printing using write()
// PARAMETER USAGE :
//    buf - A character array of size 100 containing
//          the print statement
// FUNCTION CALLED :
//    write()
// -----------------------------------------------------------
void printWrap(char buf[100]) {
    write(1, buf, strlen(buf));
}

// -----------------------------------------------------------
// FUNCTION downheap :
//    Used to restore heap properties to an array
// PARAMETER USAGE :
//    numbers - array of random numbers
//    numbersSize - Size of numbers array
//    index - index to start the heapify in the array
// FUNCTION CALLED :
//    NONE
// -----------------------------------------------------------
void downheap(int numbers[], int numbersSize, int index) {

    int leftIndex;
    int rightIndex;
    int largeChildIndex;
    int temp;
    int index2 = index; // copy of index for modifing

    while((2 * index2 + 1) < numbersSize) { // while has left child
        leftIndex = 2 * index2 + 1; // index of left child
        largeChildIndex = leftIndex;
        if ((2 * index2 + 2) < numbersSize) { // if has right child
            rightIndex = 2 * index2 + 2;
            if (numbers[rightIndex] < numbers[leftIndex]) {
                largeChildIndex = rightIndex;
            }
        }
        if (numbers[largeChildIndex] > numbers[index2]) { // done swapping
            break;
        }
        // swap the elements
        temp = numbers[index2];
        numbers[index2] = numbers[largeChildIndex];
        numbers[largeChildIndex] = temp;
        index2 = largeChildIndex;
    }
}


// -----------------------------------------------------------
// function heapify :
//    Used to create the intial heap structure
// parameter usage :
//    numbers - array of random numbers
//    numbersSize - Size of numbers array
// function called :
//    downheap()
// -----------------------------------------------------------
void heapify(int numbers[], int numbersSize) {
    int i;

    // Build the heap property
    for (i = numbersSize / 2; i >= 0; i--) {
        downheap(numbers, numbersSize, i);
    }
}

// -----------------------------------------------------------
// function heapSort :
//    Sort the data stored in numbers array using the
//    heapsort method
// parameter usage :
//    numbers - array of random numbers
//    numbersSize - Size of numbers array
// function called :
//    heapify()
//    downheap()
// -----------------------------------------------------------
void heapSort(int numbers[], int numbersSize) {
    int temp;
    int heapSize = numbersSize;
    int i;

    // create the heap
    heapify(numbers, numbersSize);
    // repeatedly swap the largest to the front of the array
    for (i = numbersSize - 1; i > 0; i--) {
        temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        heapSize = heapSize - 1;
        // rebuild the heap property
        downheap(numbers, heapSize, 0);
    }

    // I made it sort backwards so to fix, reverse the array
    int swapVar = numbersSize - 1;
    for (i = 0; i < numbersSize / 2; i++) {
       temp = numbers[i];
       numbers[i] = numbers[swapVar];
       numbers[swapVar] = temp;
       swapVar = swapVar - 1;
    }
}

// -----------------------------------------------------------
// function randomNums:
//    Method used to generate the random numbers to be sorted
//    by the heapsort method
// parameter usage :
//    m - the number of random numbers to be created
// function called :
//    memset()
//    sprintf()
//    printWrap()
//    srand()
//    rand()
//    strcat()
//    heapSort()
// -----------------------------------------------------------
void randomNums(int m) {
    char buf[100];
    char intBuf[25];
    int numbers[m];
    int j, k, i;

    memset(numbers, 0, m);

    sprintf(buf, "   Heap Sort Process Started\n");
    printWrap(buf);

    // if m is zero no numbers need to be generated so print empty lines
    if (m == 0) {
        sprintf(buf, "   Random Numbers Generated:\n\n");
        printWrap(buf);
        sprintf(buf, "   Sorted Sequence:\n\n");
        printWrap(buf);
        sprintf(buf, "   Heap Sort Process Exits\n");
        printWrap(buf);
        exit(0);
    }

    // Generate the random numbers
    srand(time(NULL));
    for (i = 0; i < m; i++) {
        numbers[i] = rand() % 100;
    }

    sprintf(buf, "   Random Numbers Generated:\n");
    printWrap(buf);
    // Print the random numbers generated
    j = 0;
    while (j < m) {
        // print out the numbers 20 per line
        sprintf(buf, "   "); // the indentation
        for (k = 0; k < 20; k++) {
            if (j < m) {
                sprintf(intBuf, "%4d ", numbers[j]);
                strcat(buf, intBuf);
                j++;
            }
        }
        strcat(buf, "\n");
        printWrap(buf);
    }

    // call heap sort
    heapSort(numbers, m);

    sprintf(buf, "   Sorted Sequence:\n");
    printWrap(buf);
    // Print the random numbers sorted
    j = 0;
    while (j < m) {
        // print out the numbers 20 per line
        sprintf(buf, "   "); // the indentation
        for (k = 0; k < 20; k++) {
            if (j < m) {
                sprintf(intBuf, "%4d ", numbers[j]);
                strcat(buf, intBuf);
                j++;
            }
        }
        strcat(buf, "\n");
        printWrap(buf);
    }


    sprintf(buf, "   Heap Sort Process Exits\n");
    printWrap(buf);
}

// -----------------------------------------------------------
// function recurseFib :
//    Used to recursively add the two numbers before it
//    together
// parameter usage :
//    n - the number to compute
//
// function called :
//    recursFib()
// -----------------------------------------------------------
long recursFib(long n) {

    if (n == 1 || n == 2) {
        return 1;
    }

    return recursFib(n - 1) + recursFib(n - 2);
}

// -----------------------------------------------------------
// function fibonacci :
//    Initial setup and caller to the recursive fibonacci
//    computation
// parameter usage :
//    n - the Fibonacci number to compute
// function called :
//    recursFib()
//    sprintf()
//    printWrap()
// -----------------------------------------------------------
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
}

// -----------------------------------------------------------
// function needleSim :
//    Calculates the Buffon's Needle problem. Calculates the
//    probabilty of throwing a needle and crossing a dividing
//    line.
// parameter usage :
//    r - the number of interations for the problem
// function called :
//    sprintf()
//    printWrap()
//    srand()
//    rand()
//    sin()
//    time()
// -----------------------------------------------------------
void needleSim(int r) {
    char buf[100];

    double dis, angle;
    double crossCount = 0;
    double result = 0;
    double finalRes = 0;
    int i;

    sprintf(buf, "         Buffon's Needle Process Started\n");
    printWrap(buf);

    srand(time(NULL));
    for (i = 0; i < r; i++) {
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

// -----------------------------------------------------------
// function integration :
//    Used to calculate the integral of sin(x) where x goes
//    from 0 to pi
// parameter usage :
//    s - number of iterations, determines accuracy
// function called :
//    sprintf()
//    printWrap()
//    srand()
//    rand()
//    time()
// -----------------------------------------------------------
void integration(int s) {
    char buf[100];

    double pointCount = 0; // number of times point(a,b)
                           // is between sin(x) and x-axis
    double result;
    double a;              // x-coordinate
    double b;              // y-coordinate
    double finalRes;       // computed area
    int i;

    srand(time(NULL));
    for (i = 0; i < s; i++) {
        b = ((double) rand())/RAND_MAX;        // random number [0, 1)
        a = (((double) rand())/RAND_MAX) * PI; // random number [0, pi)

        // if the result is greater than b, then the point (b, a)
        // is between sin(x) and the x-axis
        result = sin(a);
        if (b <= result) {
            pointCount = pointCount + 1;
        }
    }

    finalRes = (pointCount / s) * PI;

    sprintf(buf, "            Integration Process Started\n");
    printWrap(buf);
    sprintf(buf, "            Input Number %d\n", s);
    printWrap(buf);
    sprintf(buf, "            Total Hit %.0f\n", pointCount);
    printWrap(buf);
    sprintf(buf, "            Estimated Area is %.7f\n", finalRes);
    printWrap(buf);
    sprintf(buf, "            Integration Process Exits\n");
    printWrap(buf);
}

// -----------------------------------------------------------
// function main :
//    Function forks 4 processes to calculate the various
//    problems of the functions above. It then waits for the
//    children to finish before exiting
// parameter usage :
//    argc - the number of arguments from the command line
//    argv - an array of the arguments from the command line
// function called :
//    integration()
//    needleSim()
//    randomNums()
//    fibonacci()
//    fork()
//    wait()
//    exit()
//    sprintf()
//    printWrap()
// -----------------------------------------------------------
int main(int argc, char* argv[]) {

    char buf[100];
    pid_t pid;

    if (argc != 5) {
        printf("Incorrect number of arguments - Expecting 4, "
                "recieved %d\n", argc - 1);
        exit(1);
    }

    sprintf(buf, "Main Process Started\n");
    printWrap(buf);
    sprintf(buf, "Number of Random Numbers    = %d\n", atoi(argv[1]));
    printWrap(buf);
    sprintf(buf, "Fibonacci Input             = %d\n", atoi(argv[2]));
    printWrap(buf);
    sprintf(buf, "Buffon's Needle Interations = %d\n", atoi(argv[3]));
    printWrap(buf);
    sprintf(buf, "Integration Interations     = %d\n", atoi(argv[4]));
    printWrap(buf);


    int i;
    // fork the 4 processes
    for(i = 0; i < 4; i++) {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // depending on which child this is, call a different calculation
            switch(i) {
                case 0:
                    randomNums(atoi(argv[1]));
                    exit(0);
                    break;

                case 1:
                    fibonacci(atoi(argv[2]));
                    exit(0);
                    break;

                case 2:
                    needleSim(atoi(argv[3]));
                    exit(0);
                    break;

                case 3:
                    integration(atoi(argv[4]));
                    exit(0);
                    break;
            }
        }
        else {
            // print information based on which process was just created
            switch(i) {
                case 0:
                    sprintf(buf, "Heap Sort Process Created\n");
                    printWrap(buf);
                    break;

                case 1:
                    sprintf(buf, "Fibonacci Process Created\n");
                    printWrap(buf);
                    break;

                case 2:
                    sprintf(buf, "Buffon's Needle Process Created\n");
                    printWrap(buf);
                    break;

                case 3:
                    sprintf(buf, "Integration Process Created\n");
                    printWrap(buf);
                    break;
            }

        }
    }

    int status;

    sprintf(buf, "Main Process Waits\n");
    printWrap(buf);
    // wait for all 4 children to return
    for(i = 0; i < 4; i++) {
        wait(&status);
    }
    sprintf(buf, "Main Process Exits\n");
    printWrap(buf);

    exit(0);
}
