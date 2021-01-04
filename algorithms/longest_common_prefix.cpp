#include <iostream>
#include <vector>
#include <string>

using namespace std;


string longestCommonPrefix(vector<string> & strs) {

    string result = "";
    int i = 0;
    while (strs.size() > 0) {
        for (int k = 0; k < strs.size(); ++k) {
            // k > 0 to prevent the case that vector size is 1
            if (i >= strs[k].size() || (k > 0 && strs[k][i] != strs[k-1][i]))
                return result;
        }
        result += strs[0][i++];
    }
    return result;
}

void printLongestCommonPrefix(vector<string> strs) {

    cout << "Input: strs = [\"" << strs[0] << "\"";
    for (int i = 1; i < strs.size(); ++i) {
        cout << "," << "\"" << strs[i] << "\"";
    }
    string result = longestCommonPrefix(strs);
    cout << endl << "Output: \"" << result << "\"" << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printLongestCommonPrefix(vector<string> {"flower","flow","flight"});
    printLongestCommonPrefix(vector<string> {"dog","racecar","car"});
    return 0;
}