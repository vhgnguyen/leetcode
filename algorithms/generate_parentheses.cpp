#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addParentheses(vector<string> & res, string s, int l, int r) {
    if (l == 0 && r == 0) {
        res.push_back(s);
        return;
    }
    if (l > 0) addParentheses(res, s+"(", l-1, r+1);
    if (r > 0) addParentheses(res, s+")", l, r-1);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    addParentheses(res, "", n, 0);
    return res;
}

void printGenerateParenthesis(int n) {
    cout << "Input: n = " << n << endl;
    vector<string> res = generateParenthesis(n);
    cout << "Output: [";
    for (auto & s : res) {
        cout << "\"" << s << "\", "; 
    }
    cout << "]" << endl << "=======" << endl;
}


int main(int argc, char ** argv) {
    printGenerateParenthesis(3);
    printGenerateParenthesis(1);

    return 0;
}
