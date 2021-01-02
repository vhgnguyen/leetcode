#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int romanToInt(string s) {
        
        if (s.length() == 0)
            return 0;
        
        int table[256];
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;

        int result = table[s.back()];

        for (int i = s.length() - 2; i >= 0; --i) {
            if (table[s[i+1]] > table[s[i]])
                result -= table[s[i]];
            else
                result += table[s[i]];
        }

    return result;
}

void printRomanToInt(string s) {
    cout << "Input: s = \"" << s << "\"" << endl;
    int ans = romanToInt(s);
    cout << "Output: " << ans  << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printRomanToInt("III"); // -> 3
    printRomanToInt("IV"); // -> 4
    printRomanToInt("IX"); // -> 9
    printRomanToInt("LVIII"); // -> 58
    printRomanToInt("MCMXCIV"); // ->1994

}