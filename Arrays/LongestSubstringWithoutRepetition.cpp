#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s) {
    if (s.size() == 0)
        return 0;

    int maxlen = INT_MIN;
    unordered_set<char> set;

    int left = 0;
    for (int right = 0; right < s.size(); right++) {
        if (set.find(s[right]) != set.end()) {
            while (left < right && set.find(s[right]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
        }

        set.insert(s[right]);
        maxlen = max(maxlen, right - left + 1);
    }

    return maxlen;
}

int main() {
    string s = "abcabcbb";

    int len = longestSubstring(s);
    cout << len << endl;

    return 0;
}