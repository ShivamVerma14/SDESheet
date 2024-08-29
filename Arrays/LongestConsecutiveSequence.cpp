#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;

    int longest = 1;
    unordered_set<int> set;

    for (int num : nums)
        set.insert(num);

    for (int num : set) {
        if (set.find(num - 1) == set.end()) {
            int count = 1;
            int x = num;

            while (set.find(x + 1) != set.end()) {
                x++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {
    vector<int> nums = {100, 200, 1, 2, 4, 3};

    int ans = longestConsecutiveSequence(nums);
    cout << ans << endl;

    return 0;
}