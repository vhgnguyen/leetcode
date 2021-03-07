#include "helper.h"
#include <map>
#include <set>

using namespace helper;


bool isIsomorphic(string s, string t) {
    map<char, char> m;
    set<char> ct;
    for (int i = 0; i < s.length(); ++i) {
        auto it = m.find(s[i]);
        if (it == m.end()) {
            if (ct.count(t[i]) > 0) return false;
            m[s[i]] = t[i];
            ct.insert(t[i]);
        }
        else if (it->second != t[i]) {
            return false;
        }
    }
    return true;
}

void printResult(string s, string t) {
    cout << "Input: s = " << printString(s) << ", t = " << printString(t) << endl;
    cout << "Output: " << bool2str(isIsomorphic(s, t)) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult("egg", "add"); // Output: true
    printResult("foo", "bar"); // Output: false
    printResult("paper", "title"); // Output: true

    return 0;
}