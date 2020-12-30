#include <iostream>
#include <string>
#include <limits.h>

using namespace std;


int atoi(string s) {

    int sign = 1, base = 0, i = 0;

    if (s.length() == 0) 
        return 0;

    while (i < s.length() && s[i] == ' ') 
        i++;

    // because +-1 should return 0 instead of -1 so that the second symbol must be invalid
    if (i < s.length() && (s[i] == '-' || s[i] == '+')) 
        sign = (s[i++] == '-') ? -1 : 1;

    while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
            return sign == -1 ? INT_MIN : INT_MAX;
        base = 10 * base + (int)(s[i++] - '0');
    }

    return sign * base;
}


int main(int argc, char ** argv) {

    string str;
    int result;

    cout << "Input: str = ";
    cin >> str;
    result = atoi(str);
    cout << "Output: " << result;

    return 0;
}
