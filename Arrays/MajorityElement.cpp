#include <iostream>
#include <vector>
using namespace std;

// Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
    int count = 0;
    int element;

    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            element = nums[i];
            count++;
        }
        else if (element == nums[i])
            count++;
        else
            count--;
    }

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == element)
            cnt++;

    if (cnt > (nums.size() / 2))
        return element;

    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int ans = majorityElement(nums);
    cout << ans << endl;

    return 0;
}