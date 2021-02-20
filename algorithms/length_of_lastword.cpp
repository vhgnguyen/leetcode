#include <iostream>
#include <string>

using namespace std;


int lengthOfLastWord(string s) {
    for (size_t i = s.length() - 1; i > 0; --i) {
        if (s.at(i) != ' ')
            break;
        else 
            s.erase(i, 1);
    }
    size_t found = s.rfind(' ');
    return s.substr(found+1).length();
}

void printResult(string s) {
    cout << "Input : s = \"" << s << "\"" << endl;
    int res = lengthOfLastWord(s);
    cout << "Output: " << res << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult("Hello World"); // Output: 5
    printResult(" "); // Output: 0

    return 0;
}