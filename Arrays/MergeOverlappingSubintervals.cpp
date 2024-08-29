#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++) {
        if (ans.empty() || intervals[i][0] > ans.back()[1])
            ans.push_back(intervals[i]);
        else
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
    
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> ans = merge(intervals);

    for (auto& interval : ans) {
        for (int& ele : interval) 
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}