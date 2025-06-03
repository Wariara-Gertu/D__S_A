#include <iostream>
using namespace std;

int singleNumber(int nums[], int length) {
int result = 0;
for (int i = 0; i < length; i++) {
result ^= nums[i]; // XOR logic
}
return result;
}

int main() {
int nums[] = {1, 2, 2, 3, 3, 1, 5};
int length = sizeof(nums) / sizeof(nums[0]);
int single = singleNumber(nums, length);
cout << "Single number: " << single << endl;
return 0;
}