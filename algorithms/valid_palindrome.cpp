#include "helper.h"

using namespace std;
using namespace helper;

bool isPalindrome(string s) {
    string ns = "";
    for (char c : s) {
        if (isalpha(c) || isdigit(c)) ns += tolower(c);
    }
    int l = 0, r = ns.length() - 1;
    while (l <= r) {
        if (ns[l++] != ns[r--]) return false;
    }
    return true;
}

void printResult(string s) {
    cout << "Input: s = " << printString(s) << endl;
    string res = isPalindrome(s) ? "true" : "false";
    cout << "Output: " << res << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {
    printResult("A man, a plan, a canal: Panama"); // Output: true
    printResult("race a car"); // Output: false

    return 0;
}