#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;

    vector<int> temp;
    int count = 0;

    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            count += (mid - i + 1);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(nums[j]);
        j++;
    }

    for (int k = low; k <= high; k++)
        nums[k] = temp[k - i];

    return count;
}

int mergeSort(vector<int>& nums, int low, int high) {
    int count = 0;

    if (low >= high)
        return count;

    int mid = (low + high) / 2;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);

    return count;
}

int countInversions(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};

    int count = countInversions(nums);
    cout << count << endl;

    return 0;
}