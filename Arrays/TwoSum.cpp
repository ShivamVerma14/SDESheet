#include <bits/stdc++.h>
using namespace std;

/*
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];

        if (m.find(diff) != m.end()) {
            return {m[diff], i};
        }

        m[nums[i]] = i;
    }

    return {-1, -1};
}
*/

bool twoSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}

int main() {
    vector<int> nums = {2, 6, 5, 8, 11};
    int target = 14;

    if (twoSum(nums, target))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;
}