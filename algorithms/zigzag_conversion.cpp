#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

    /**
     * One for loop with direction parameter
     */
    string convert2(string s, int numRows) {

        if (numRows == 1)
            return s;

        vector<string> c(numRows);
        int row = 0, i = 0;
        int increase = -1;

        while (i < s.length()) {
            if (i % (numRows - 1) == 0) {
                increase *= -1;
            }
            c[row].push_back(s[i++]);
            row += increase;
        }

        string result;
        for (auto const & j : c) {
            result += j;
        }

        return result;
    };
    
    /**
     * Without direction parameter
     */
    string convert1(string s, int numRows) {

        if (numRows == 1)
            return s;

        vector<string> c(numRows);
        int n = s.length();
        int i = 0;

        while (i < n) {
            for (int j = 0; j < numRows && i < n; ++j) {
                c[j].push_back(s[i++]);
            }
            for (int j = numRows - 2; j > 0 && i < n; --j) {
                c[j].push_back(s[i++]);
            }
        }

        string result;
        for (auto const & k : c) {
            result += k;
        }

        return result;
    };
};


int main(int argc, char ** argv) {

    string s = "PAYPALISHIRING";
    int numRows = 3;

    Solution sol;
    string result1 = sol.convert1(s, numRows);
    string result2 = sol.convert2(s, numRows);

    cout << "Input : " << s << endl;
    cout << "Output1: " << result1 << endl;
    cout << "Output2: " << result2;

    return 0;
}