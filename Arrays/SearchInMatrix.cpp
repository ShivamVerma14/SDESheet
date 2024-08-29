#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>>& mat, int key) {
    int n = mat.size();
    int m = mat[0].size();

    int beg = 0;
    int end = n * m - 1;

    while (beg <= end) {
        int mid = (beg + end) / 2;

        int row = mid / m;
        int col = mid % m;

        if (mat[row][col] == key)
            return true;
        else if (mat[row][col] < key)
            beg = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int key = 8;

    if (search(mat, key))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}