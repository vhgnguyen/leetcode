#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Dynamic programming solution:
 * Define matching matrix dp[m+1][n+1] with dp[0][0] = true (for empty string) and:
 *      dp[i][j] = true if s[0,i-1] matches p[0, j-1]
 * 
 * We separate two cases of p[j-1]:
 * 
 * 1) if p[j-1] is not '*', s[i-1] matches p[j-1] OR p[j-1] is '.' (which means any single character is matched):
 *      dp[i][j] = dp[i-1][j-1] if s[i-1] == p[j-1] || p[j-1] == '.'
 * 
 * 2) if p[j-1] is '*':
 *  s[i-1] matches up to p[i-3] so that p[j-2] could match zero or more:
 *      dp[i][j] = dp[i][j-2]
 *  OR s[i-1] should match up to p[j-2] or p[j-2] is '.', when s[i-2] already matched p[j-1]:
 *      dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'))
 */
bool isMatch(string s, string p) {

    int m = s.length();
    int n = p.length();

    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

    dp[0][0] = true;

    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] != '*') {
                dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }            
            else {
                dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            }
        }
    }

    return dp[m][n];
}

void printIsMatch(string s, string p) {
    bool result = isMatch(s, p);
    string result_str = result ? "true" : "false";
    cout << "Input: s = \"" << s << "\", p = \"" << p << "\"" << endl;
    cout << "Output: " << result_str << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printIsMatch("aa", "a"); // Output: false
    printIsMatch("aa", "a*"); // Output: true
    printIsMatch("ab", ".*"); // Output: true
    printIsMatch("aab", "c*a*b"); // Output: true
    printIsMatch("mississippi", "mis*is*p*."); // Output: false

    return 0;
}