#include <bits/stdc++.h>
using namespace std;

void findCombinations(vector<int>& nums, int index, int target, vector<int> temp, vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    
    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1])
            continue;

        if (nums[i] > target)
            break;

        temp.push_back(nums[i]);
        findCombinations(nums, i + 1, target - nums[i], temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    sort(nums.begin(), nums.end());
    findCombinations(nums, 0, target, temp, ans);
    return ans;
}

int main() {
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = combinationSum(nums, target);
    for (auto& row : ans) {
        for (int& num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}