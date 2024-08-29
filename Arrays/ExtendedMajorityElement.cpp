#include <bits/stdc++.h>
using namespace std;

vector<int> findMajorityElements(vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    int limit = nums.size() / 3;
    vector<int> ans;

    for (auto& [element, count] : freq) {
        if (count > limit)
            ans.push_back(element);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 2};

    vector<int> elements = findMajorityElements(nums);
    for (int& num : elements)
        cout << num << " ";

    return 0;
}