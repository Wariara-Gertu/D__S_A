#include <iostream>

// Function to calculate the sum of elements in an integer array
int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum element in an integer array
int maximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;

    // Prompt user for the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Check if n is non-negative
    if (n < 0) {
        std::cerr << "Invalid array size.\n";
        return 1;
    }

    // Dynamically allocate memory for the array
    int *arr = new int[n];

    // Prompt user to enter n integers and store them in the array
    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Calculate summation and maximum
    int sum = summation(arr, n);
    int max = maximum(arr, n);

    // Display the results
    std::cout << "Sum of the integers: " << sum << std::endl;
    std::cout << "Maximum integer: " << max << std::endl;

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}