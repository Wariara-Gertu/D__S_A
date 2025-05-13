#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int length) {
if (length == 0) return 0;
int i = 0;
for (int j = 1; j < length; j++) {
if (nums[j] != nums[i]) {
i++;
nums[i] = nums[j];
}
}
return i + 1;
}

int main() {
int nums[] = {1, 1, 2, 2, 3, 3, 4, 5, 5};
int length = sizeof(nums) / sizeof(nums[0]);
int newLength = removeDuplicates(nums, length);
cout << "New length: " << newLength << endl;
cout << "Array: ";
for (int i = 0; i < newLength; i++) {
cout << nums[i] << " ";
}
cout << endl;
return 0;
}