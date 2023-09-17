#include <iostream>
#include <ctime>
#include <cstdlib>

const int N = 4;

// A function that generates a random array with values from 10 to 99
void generateRandomArray(int arr[][N]) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = rand() % 90 + 10; // Generate a random number between 10 and 99
        }
    }
}

// A function that rotates the array 90 degrees clockwise
void rotateArray(int arr[][N], int rotated[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[i][j] = arr[N - 1 - j][i];
        }
    }
}

// A function that prints an array
void printArray(int arr[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Initialize the original array
    int arr[N][N];

    // Generate a random array
    generateRandomArray(arr);

    // Print the original array
    std::cout << "Original array:" << std::endl;
    printArray(arr);

    // Create the new array
    int rotated[N][N];

    // Rotate the array
    rotateArray(arr, rotated);

    // Print the rotated array
    std::cout << "\nRotated array:" << std::endl;
    printArray(rotated);

    return 0;
}
