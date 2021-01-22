#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Brute force approach, time complexity O(m*(m-n-1))
 */
int strStr1(string haystack, string needle) {

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

/** 
 * Knuth Morris Pratt (KMP) algorithm, time complexity O(m+n)
 * lps stands for Longest proper Prefix and Suffix
 */
vector<int> KMP(string needle) {

    int n = needle.size();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;) {
        if (needle[i] == needle[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int strStr(string haystack, string needle) {

    int m = haystack.length(), n = needle.length();
    if (n == 0) 
        return 0;
    vector<int> lps = KMP(needle);
    for (int i = 0, j = 0; i < m;) {
        if (haystack[i] == needle[j]) { 
            i++, j++;
        }
        if (j == n) {
            return i - j;
        }
        if (i < m && haystack[i] != needle[j]) {
            j ? j = lps[j - 1] : i++;
        }
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