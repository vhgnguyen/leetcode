#include <iostream>
#include <string>
#include <limits.h>

using namespace std;


int atoi(string s) {

    int sign = 1, sum = 0, i = 0;

    if (s.length() == 0) 
        return 0;

    while (i < s.length() && s[i] == ' ') 
        i++;

    // because +-1 should return 0 instead of -1 so that the second symbol must be invalid
    if (i < s.length() && (s[i] == '-' || s[i] == '+')) 
        sign = (s[i++] == '-') ? -1 : 1;

    while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
        if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
            return sign == -1 ? INT_MIN : INT_MAX;
        sum = sum * 10 + (int)(s[i++] - '0');
    }

    return sum * sign;
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
