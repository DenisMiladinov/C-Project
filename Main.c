#include <stdio.h>

#define MAX 100  // maximum size for the matrix

// Prints the task description
void printInstructions() {
    printf("Task: Process a 2D array A[N][N] with values in range [-500, 1000]\n");
    printf("Steps:\n");
    printf("1. Input the array\n");
    printf("2. Print the array\n");
    printf("3. Create array C with smallest elements from each column\n");
    printf("4. Sort array C in ascending order\n");
    printf("5. Print C before and after sorting\n\n");
}

// Prints the author's name
void printAuthor() {
    printf("Author: Denis Lubomirov Miladinov\n\n");
}

// Inputs elements into the matrix with validation
void inputArray(int A[MAX][MAX], int N) {
    printf("Enter elements of the array:\n");
    for (int i = 0; i < N; i++) {          // loop through rows
        for (int j = 0; j < N; j++) {      // loop through columns
            do {
                printf("A[%d][%d] = ", i, j);
                scanf("%d", &A[i][j]);
            } while (A[i][j] < -500 || A[i][j] > 1000); // validate range
        }
    }
}

// Prints the matrix
void printArray(int A[MAX][MAX], int N) {
    printf("\nMatrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%5d ", A[i][j]);  // formatted output
        }
        printf("\n");
    }
}

// Creates array C with the smallest element from each column
void createC(int A[MAX][MAX], int C[MAX], int N) {
    for (int j = 0; j < N; j++) {     // for each column
        int min = A[0][j];           // assume first element is smallest
        for (int i = 1; i < N; i++) {
            if (A[i][j] < min) {     // find smaller value
                min = A[i][j];
            }
        }
        C[j] = min;                 // store result in C
    }
}

// Prints array C
void printC(int C[MAX], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");
}

// Sorts array C in ascending order using bubble sort
void sortC(int C[MAX], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (C[j] > C[j + 1]) {  // swap if elements are in wrong order
                int temp = C[j];
                C[j] = C[j + 1];
                C[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    int A[MAX][MAX];  // 2D array
    int C[MAX];       // 1D array

    printInstructions(); // print task info
    printAuthor();       // print author

    printf("Enter N (size of matrix): ");
    scanf("%d", &N);

    inputArray(A, N);   // read matrix
    printArray(A, N);   // display matrix

    createC(A, C, N);  // create array C

    printf("\nArray C (before sorting):\n");
    printC(C, N);

    sortC(C, N);       // sort array C

    printf("Array C (after sorting):\n");
    printC(C, N);

    return 0;          // end program
}