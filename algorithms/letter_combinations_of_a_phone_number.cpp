#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits) {

    if (digits.size() == 0)
        return {};
    
    static const vector<string> table = 
        {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> result = {""};

    for (auto & i : digits) {
        int num = i - '0';
        if (num < 2 || num > 9)
            break;
        const string & pos = table[num];
        vector<string> tmp;
        for (auto & j : pos) {
            for (auto & k : result) {
                tmp.push_back(k + j);
            }
        }
        result.swap(tmp);
    }

    return result;
}

void printLetterCombinations(string digits) {
    vector<string> result = letterCombinations(digits);
    cout << "Input: digit = \"" << digits << "\"" << endl;
    cout << "Output: [";
    for (auto & i : result) {
        cout << "\"" << i << "\",";
    }
    cout << "]" << endl << "=======" << endl;
}


int main(int argc, char ** argv) {
    printLetterCombinations("23");
    printLetterCombinations("");
    printLetterCombinations("2");
    return 0;
}