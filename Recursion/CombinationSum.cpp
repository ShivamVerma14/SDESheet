#include <bits/stdc++.h>
using namespace std;

void findCombinations(vector<int>& nums, int index, int target, vector<int> temp, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        if (target == 0)
            ans.push_back(temp);

        return;
    }

    if (nums[index] <= target) {
        temp.push_back(nums[index]);
        findCombinations(nums, index, target - nums[index], temp, ans);
        temp.pop_back();
    }

    findCombinations(nums, index + 1, target, temp, ans);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    findCombinations(nums, 0, target, temp, ans);
    return ans;
}

int main() {
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(nums, target);
    for (auto& row : ans) {
        for (int& num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}