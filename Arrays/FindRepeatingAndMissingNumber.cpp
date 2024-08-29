#include <bits/stdc++.h>
using namespace std;

pair<int, int> findNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n + 1, 0);

    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    pair<int, int> ans;

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0)
            ans.second = i;
        else if (freq[i] > 1)
            ans.first = i;
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};

    pair<int, int> ans = findNumbers(nums);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}