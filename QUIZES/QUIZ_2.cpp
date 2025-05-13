#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end) {
while (start < end) {
int temp = arr[start];
arr[start] = arr[end];
arr[end] = temp;
start++;
end--;
}
}

void rotate(int nums[], int length, int k) {
k = k % length;
reverse(nums, 0, length - 1);
reverse(nums, 0, k - 1);
reverse(nums, k, length - 1);
}

int main() {
int nums[] = {1, 2, 3, 4, 5, 6, 7};
int length = sizeof(nums) / sizeof(nums[0]);
int k = 3;
rotate(nums, length, k);
cout << "Rotated array: ";
for (int i = 0; i < length; i++) {
cout << nums[i] << " ";
}
cout << endl;
return 0;
}