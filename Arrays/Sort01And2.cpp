#include <iostream>
#include <vector>
using namespace std;

// Dutch National Flag Algorithm
void sort(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sort(nums);
    for (int& num : nums)
        cout << num << " ";

    return 0;
}