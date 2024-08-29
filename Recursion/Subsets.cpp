#include <bits/stdc++.h>
using namespace std;

void findSubsets(vector<int>& nums, int index, vector<int> temp, set<vector<int>>& res) {
    if (index == nums.size()) {
        sort(temp.begin(), temp.end());
        res.insert(temp);
        return;
    }

    temp.push_back(nums[index]);
    findSubsets(nums, index + 1, temp, res);
    temp.pop_back();
    findSubsets(nums, index + 1, temp, res);
}

vector<vector<int>> findUniqueSubsets(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>> res;
    
    vector<int> temp;
    findSubsets(nums, 0, temp, res);

    for (auto it = res.begin(); it != res.end(); it++) {
        ans.push_back(*it);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = findUniqueSubsets(nums);

    for (auto& row : ans) {
        for (int& num : row)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}