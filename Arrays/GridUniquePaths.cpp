#include <iostream>
#include <vector>
using namespace std;

int countPaths(int i, int j, int n, int m, vector<vector<int>>& dp) {
    if ((i == n - 1) && (j == m - 1))
        return 1;

    if (i >= n || j >= m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = countPaths(i + 1, j, n, m, dp) + countPaths(i, j + 1, n, m, dp);
}

int countUniquePaths(int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    
    int ans = countPaths(0, 0, n, m, dp);
    if (n == 1 && m == 1)
        return ans;

    return dp[0][0];
}

int main() {
    int n = 3;
    int m = 7;

    int paths = countUniquePaths(n, m);
    cout << paths << endl;

    return 0;
}