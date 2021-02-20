#include <iostream>
#include <string>

using namespace std;


string addBinary(string a, string b) {
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    string res = "";
    while (i >= 0 || j >= 0) {
        if (i >= 0) {
            carry += a[i] == '0' ? 0 : 1;
            i--;
        }
        if (j >= 0) {
            carry += b[j] == '0' ? 0 : 1;
            j--;
        }
        res = ((carry%2) == 0 ? '0' : '1') + res;
        carry /= 2;
    }
    return carry == 1 ? '1' + res : res;
}

void printResult(string a, string b) {
    cout << "Input: a = \"" << a << "\", b = \"" << b << "\"" << endl;
    string res = addBinary(a, b);
    cout << "Output: \"" << res << "\"" << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult("11", "1"); // Output : "100"
    printResult("1010", "1011"); // Output : "10101"

    return 0;
}