#include <iostream>
#include <vector>
using namespace std;

void recurPrint(int index, vector<int>& nums, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        vector<int> temp(nums);
        ans.push_back(temp);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        recurPrint(index + 1, nums, ans);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    recurPrint(0, nums, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<vector<int>> permutations = permute(nums);
    for (auto& row : permutations) {
        for (int& ele : row)
            cout << ele << " ";

        cout << endl;
    }

    return 0;
}