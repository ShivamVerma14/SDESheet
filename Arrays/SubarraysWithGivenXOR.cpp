#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    int xr = 0;
    unordered_map<int, int> map;

    map[xr]++;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        xr = xr ^ nums[i];
        int x = xr ^ k;

        count += map[x];
        map[xr]++;
    }

    return count;
}

int main() {
    vector<int> nums {4, 2, 2, 6, 4};
    int k = 6;

    int count = countSubarrays(nums, k);
    cout << count << endl;

    return 0;
}