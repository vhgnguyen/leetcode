#include <iostream>
#include <algorithm>


using namespace std;


class Solution {

public:
    string longestPalindrome(string s) {

        int n = s.length();
        int i = 0, l = 0, r = 0, left = 0, max_len = 0;

        while (i < n - max_len / 2 ) {
            l = i;
            r = i;
            while (r < n && s[r] == s[r+1]) 
                r++;
            i = r + 1;
            while (l > 0 && r < n-1 && s[l-1] == s[r+1]) {
                r++;
                l--;
            }
            int tmp_len = r - l + 1;
            if (tmp_len > max_len) {
                max_len = tmp_len;
                left = l;
            }
        }
        return s.substr(left, max_len);
    }
};


int main(int argv, char ** argc) {

    string s;
    cout << "Input: s = ";
    cin >> s;

    Solution sol;
    string result = sol.longestPalindrome(s);
    cout << endl << "Output: \"" << result << "\"" << endl;

    return 0;
}