#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {

public:

    /**
     * One map solution
     */
    int lengthOfLongestSubstring1(string s) {

        map<char, int> m;
        int maxLen = 0;
        int lastPos = -1;

        for (int i = 0; i < s.size(); i++) {
            if ((m.find(s[i]) != m.end()) && (lastPos < m[s[i]])) {
                lastPos = m[s[i]];
            }
            if (i - lastPos > maxLen) {
                maxLen = i - lastPos;
            }
            m[s[i]] = i;
        }        
        
        return maxLen;
    }

    /**
     * Set solution 
     */
    int lengthOfLongestSubstring2(string s) {

        int i = 0, j = 0, maxLen = 0;
        unordered_set<char> sc;

        while (i < s.length() && j < s.length()) {
            if (sc.find(s[j]) == sc.end()) {
                sc.insert(s[j++]);
                maxLen = max(maxLen, j - i);
            }
            else {
                sc.erase(s[i++]);
            }
        }

        return maxLen;
    }

    /**
     * Vector solution with char index
     */
    int lengthOfLongestSubstring3(string s) {
        
        vector<int> v(256, -1);
        int maxLen=0, lastPos = -1;

        for (int i = 0; i != s.length(); i++) {
            if (v[s[i]] > lastPos) // only happens if char appeared
                lastPos = v[s[i]]; // get index in string of last appeared char
            v[s[i]] = i; // replace with current index
            maxLen = max(maxLen, i - lastPos); // from last to current appearance index
        }
        
        return maxLen;
    }

};


int main(int argc, char** argv) {

    cout << "Input: ";
    string s;
    cin >> s;
    cout << "Inpupt: s = \"" << s <<"\"" << endl;

    Solution sol;
    int result = sol.lengthOfLongestSubstring3(s);
    cout << "Output: " << result << endl;

    return 0;

}