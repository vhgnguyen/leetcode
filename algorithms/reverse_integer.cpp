#include <iostream>
#include <limits.h>

using namespace std;


class Solution {

public:

    int reverse(int x) {

        int result = 0;
        for (; x; result = result * 10 + x % 10, x /= 10);

        return result < INT_MIN || result > INT_MAX ? 0 : result;
    }
};


int main(int argv, char ** argc) {
    
    int x;
    cout << "Input : ";
    cin >> x;

    Solution sol;
    int result = sol.reverse(x);
    
    cout << "Output: " << result;

    return 0;
}