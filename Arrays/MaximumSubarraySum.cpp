#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int>& nums) {
    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;

        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            maxSum = max(sum, maxSum);
        }
    }

    return maxSum;
}

// Kadane's Algorithm
int maxSubarraySum(vector<int>& nums) {
    int maxSum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum > maxSum)
            maxSum = sum;

        if (sum < 0)
            sum = 0;
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int sum = maxSubarraySum(nums);
    cout << sum << endl;

    return 0;
}