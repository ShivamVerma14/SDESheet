#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;

        start++;
        end--;
    }

    return true;
}

void backtrack(const string& s, int start, vector<string>& temp, vector<vector<string>>& ans) {
    if (start == s.size()) {
        ans.push_back(temp);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            temp.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> getPartitions(const string& s) {
    vector<vector<string>> ans;
    vector<string> temp;

    backtrack(s, 0, temp, ans);
    return ans;
}

int main() {
    string s = "aabb";
    vector<vector<string>> partitions = getPartitions(s);

    for (auto& partition : partitions) {
        for (string& str : partition) 
            cout << str << " ";

        cout << endl;
    }

    return 0;
}