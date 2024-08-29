#include <iostream>
#include <vector>
using namespace std;

void setMatrixZero(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] == 1 || col[j] == 1) {
                mat[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    setMatrixZero(mat);

    for (auto& row : mat) {
        for (int& element : row)
            cout << element << " ";

        cout << endl;
    }

    return 0;
}