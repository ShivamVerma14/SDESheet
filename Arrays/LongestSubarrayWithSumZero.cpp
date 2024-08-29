#include <bits/stdc++.h>
using namespace std;

int findSubarrayWithSumZero(vector<int>& nums) {
    int maxlen = INT_MIN;
    unordered_map<int, int> map;

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == 0)
            maxlen = i + 1;
        else {
            if (map.find(sum) != map.end()) {
                maxlen = max(maxlen, i - map[sum]);
            }
            else {
                map[sum] = i;
            }
        }
    }

    return maxlen;
}

int main() {
    vector<int> nums = {9, -3, 3, -1, 6, -5};

    int len = findSubarrayWithSumZero(nums);
    cout << len << endl;

    return 0;
}