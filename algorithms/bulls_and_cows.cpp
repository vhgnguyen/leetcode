#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {

public:

    string getHint(string secret, string guess) {

        int sz = secret.length();
        if (sz == 0 || sz != guess.length())
            return "0A0B";

        int bulls = 0, cows = 0;
        vector<int> nr(10);

        for (int i = 0; i < sz; i++) {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else {
                if (nr[secret[i] - '0']++ < 0) 
                    cows ++;
                if (nr[guess[i] - '0']-- > 0)
                    cows ++;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }

};


int main(int argc, char** argv) {
    
    string secret, guess, result;

    cout << "secret = ";
    cin >> secret;
    int secret_ = stoi(secret);

    cout << "guess = ";
    cin >> guess;
    int guess_ = stoi(guess);

    Solution sol;
    result = sol.getHint(secret, guess);
    cout << "Output: " << result << endl;

    return 0;
}