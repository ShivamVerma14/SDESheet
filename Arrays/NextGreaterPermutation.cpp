#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int idx = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    for (int i = n - 1; i > idx; i--) {
        if (nums[i] > nums[idx]) {
            swap(nums[i], nums[idx]);
            break;
        }
    }

    reverse(nums.begin() + idx + 1, nums.end());
    return nums;
}

int main() {
    vector<int> nums = {1, 4, 5, 3, 2};
    vector<int> ans = nextPermutation(nums);

    for (int& ele : ans)
        cout << ele << " ";

    return 0;
}