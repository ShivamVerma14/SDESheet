#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    for (int i = 1; i <= n; i++) {
        vector<int> row;
        row.push_back(1);

        long long element = 1;

        for (int j = 1; j < i; j++) {
            element = element * (i - j);
            element /= j;
            row.push_back(element);
        }

        ans.push_back(row);
    }

    return ans;
}

int main() {
    int n = 6;
    
    vector<vector<int>> triangle = pascalTriangle(n);
    for (auto& row : triangle) {
        for (int& element : row)
            cout << element << " ";

        cout << endl;
    }

    return 0;
}