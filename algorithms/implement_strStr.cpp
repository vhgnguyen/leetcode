#include <iostream>
#include <string>

using namespace std;


int strStr(string haystack, string needle) {

    int m = haystack.length(), n = needle.length();
    int i = 0;
    while (i <= m-n) {
        int j = 0;
        while (j < n) {
            if (haystack[i+j] == needle[j]) {
                j++;
            }
            else 
                break;
        }
        if (j == n) 
            return i;
        i++;
    }  
    return -1;
}

void printResult(string haystack, string needle) {
    cout << "Input: haystack = \"" << haystack << "\", needle = \"" << needle << "\"" << endl;
    int res = strStr(haystack, needle);
    cout << "Output: " << res << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult("hello", "ll");
    printResult("aaaaa", "bba");
    printResult("", "");

    return 0;
}