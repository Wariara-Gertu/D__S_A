#include <iostream>
using namespace std;

bool containsDuplicate(int nums[], int length) {
for (int i = 0; i < length; i++) {
for (int j = i + 1; j < length; j++) {
if (nums[i] == nums[j]) {
return true;
}
}
}
return false;
}

int main() {
int nums[] = {1, 2, 3, 4, 5, 2};
int length = sizeof(nums) / sizeof(nums[0]);
bool result = containsDuplicate(nums, length);
cout << "Contains duplicate: " << (result ? "true" : "false") << endl;
return 0;
}