#include <stdio.h>

#define MAX 100   // Maximum allowed size for the matrix

int main() {
    int num;                  // Size of the matrix (num x num)
    int matrix[MAX][MAX];        // Two-dimensional array
    int arr[MAX];             // Array to store column minimums

    // Print task instructions
    printf("Process a 2D array matrix[num][num] with values in [-500, 1000]\n");
    printf("Find smallest element in each column, store in arr[num], sort arr\n\n");

    // Print author name
    printf("Author: Denis Miladinov\n\n");

    // Input size of the matrix
    printf("Enter size num: ");
    scanf("%d", &num);

    // Input elements of array matrix with validation
    printf("Enter elements of array matrix:\n");
    for (int i = 0; i < num; i++) {          // Loop through rows
        for (int j = 0; j < num; j++) {      // Loop through columns
            do {
                printf("matrix[%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
            } while (matrix[i][j] < -500 || matrix[i][j] > 1000); // Ensure valid range
        }
    }

    // Print the entered matrix matrix
    printf("\nArray matrix:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("%5d ", matrix[i][j]);   // Print each element with spacing
        }
        printf("\n");
    }

    // Find the smallest element in each column and store in arr
    for (int j = 0; j < num; j++) {
        int min = matrix[0][j];             // Assume first element is the smallest
        for (int i = 1; i < num; i++) {
            if (matrix[i][j] < min) {      // Compare with other elements in column
                min = matrix[i][j];
            }
        }
        arr[j] = min;                   // Store result in array arr
    }

    // Print array arr before sorting
    printf("\nArray arr (before sorting):\n");
    for (int i = 0; i < num; i++) {
        printf("%5d ", arr[i]);
    }

    // Sort array arr in ascending order using Bubble Sort
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print array arr after sorting
    printf("\n\nArray arr (after sorting):\n");
    for (int i = 0; i < num; i++) {
        printf("%5d ", arr[i]);
    }

    printf("\n");

    return 0;   // End of program
}