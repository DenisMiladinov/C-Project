#include <stdio.h>

#define MAX 100  // maximum size for the matrix

// Prints the task description
void printInstructions() {
    printf("Task: Process a 2D array matrix[num][num] with values in range [-500, 1000]\n");
    printf("Steps:\n");
    printf("1. Input the array\n");
    printf("2. Print the array\n");
    printf("3. Create array arr with smallest elements from each column\n");
    printf("4. Sort array arr in ascending order\n");
    printf("5. Print arr before and after sorting\n\n");
}

// Prints the author's name
void printAuthor() {
    printf("Author: Denis Lubomirov Miladinov\n\n");
}

// Inputs elements into the matrix with validation
void inputArray(int matrix[MAX][MAX], int num) {
    printf("Enter elements of the array:\n");
    for (int i = 0; i < num; i++) {          // loop through rows
        for (int j = 0; j < num; j++) {      // loop through columns
            do {
                printf("matrix[%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
            } while (matrix[i][j] < -500 || matrix[i][j] > 1000); // validate range
        }
    }
}

// Prints the matrix
void printArray(int matrix[MAX][MAX], int num) {
    printf("\nMatrix matrix:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("%5d ", matrix[i][j]);  // formatted output
        }
        printf("\n");
    }
}

// Creates array arr with the smallest element from each column
void createArray(int matrix[MAX][MAX], int arr[MAX], int num) {
    for (int j = 0; j < num; j++) {     // for each column
        int min = matrix[0][j];           // assume first element is smallest
        for (int i = 1; i < num; i++) {
            if (matrix[i][j] < min) {     // find smaller value
                min = matrix[i][j];
            }
        }
        arr[j] = min;                 // store result in arr
    }
}

// Prints array arr
void printArray(int arr[MAX], int num) {
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Sorts array arr in ascending order using bubble sort
void sortArray(int arr[MAX], int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // swap if elements are in wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num;
    int matrix[MAX][MAX];  // 2D array
    int arr[MAX];       // 1D array

    printInstructions(); // print task info
    printAuthor();       // print author

    printf("Enter num (size of matrix): ");
    scanf("%d", &num);

    inputArray(matrix, num);   // read matrix
    printArray(matrix, num);   // display matrix

    createC(matrix, arr, num);  // create array arr

    printf("\nArray arr (before sorting):\n");
    printC(arr, num);

    sortC(arr, num);       // sort array arr

    printf("Array arr (after sorting):\n");
    printC(arr, num);

    return 0;          // end program
}