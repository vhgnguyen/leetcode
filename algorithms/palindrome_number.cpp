#include <iostream>

using namespace std;


bool isPalindrome(int x) {

    if (x < 0 || (x > 0 && x % 10 == 0))
        return false;

    int sum = 0;
    while (sum < x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return x == sum || x == sum / 10;
}


int main(int argc, char ** argv) {

    int x;
    bool result;
    cout << "Input: x = ";
    cin >> x;
    result = isPalindrome(x);
    string result_str = result ? "true" : "false";
    cout << "Output: " << result_str;
    return 0;
}