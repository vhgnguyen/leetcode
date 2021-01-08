#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool isValid(string s) {
    
    stack<char> res;
    for (auto & c : s) {
        switch(c) {
            case('('): res.push(')'); break;
            case('['): res.push(']'); break;
            case('{'): res.push('}'); break;
            default:
                if (res.size() == 0 || c != res.top()) return false;
                else res.pop();
        }
    }
    return res.size() == 0;
}

void printIsValid(string s) {
    cout << "Input: s = \"" << s << "\"" << endl;
    bool result = isValid(s);
    string result_str = result ? "true" : "false";
    cout << "Output: " << result_str << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printIsValid("()"); // true
    printIsValid("()[]{}"); // true
    printIsValid("(]"); // false
    printIsValid("([)]"); // false
    printIsValid("{[]}"); // true

    return 0;
}