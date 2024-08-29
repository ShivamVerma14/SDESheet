#include <bits/stdc++.h>
using namespace std;

void subsetSumHelper(vector<int>& arr, int index, int n, vector<int>& ans, int sum) {
    if (index == n)  {
        ans.push_back(sum);
        return;
    }

    subsetSumHelper(arr, index + 1, n, ans, sum + arr[index]);
    subsetSumHelper(arr, index + 1, n, ans, sum);
}

vector<int> subsetSum(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();

    subsetSumHelper(arr, 0, n, ans, 0);
    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<int> arr {3, 1, 2};
    vector<int> sum = subsetSum(arr);

    for (int& s : sum)
        cout << s << " ";

    return 0;
}