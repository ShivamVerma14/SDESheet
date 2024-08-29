#include <bits/stdc++.h>
using namespace std;

void permute(string& s, int start, vector<string>& res) {
    if (start == s.size()) {
        res.push_back(s);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        swap(s[start], s[end]);
        permute(s, start + 1, res);
        swap(s[start], s[end]);
    }
}

string getPermutation(int n, int k) {
    string s;
    vector<string> res;

    for (int i = 1; i <= n; i++)
        s.push_back(i + '0');

    permute(s, 0, res);
    sort(res.begin(), res.end());

    auto it = res.begin() + (k - 1);
    return *it;
}

int main() {
    int n = 3;
    int k = 3;

    string ans = getPermutation(n, k);
    cout << ans << endl;

    return 0;
}