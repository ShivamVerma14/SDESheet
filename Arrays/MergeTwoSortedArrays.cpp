#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, vector<int>& b) {
    int i = a.size() - 1;
    int j = 0;

    while (i >= 0 && j < b.size()) {
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
            i--;
            j++;
        }
        else
            break;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    vector<int> a = {1, 4, 8, 10};
    vector<int> b = {2, 3, 9};

    merge(a, b);

    for (int& e : a)
        cout << e << " ";

    cout << endl;

    for (int& e : b)
        cout << e << " ";

    return 0;
}