#include <iostream>
#include <string>

using namespace std;


string intToRoman2(int num) {

    string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                          {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                          {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                          {"", "M", "MM", "MMM"}};
    
    return table[3][num / 1000] + table[2][(num % 1000) / 100] + \
            table[1][(num % 100) / 10] + table[0][num % 10];
}

string intToRoman1(int num) {

    string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                          {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                          {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                          {"", "M", "MM", "MMM"}};
    
    string ans;
    int i = 0;
    
    while (num > 0) {
        ans = table[i++][num % 10] + ans;
        num /= 10;
    }
    
    return ans;
}

void printIntToRoman(int num) {
    cout << "Input: num = " << num << endl;
    string ans1 = intToRoman1(num);
    string ans2 = intToRoman2(num);
    cout << "Output1: " << ans1 << ", Output2: " << ans2 << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printIntToRoman(3); // -> III
    printIntToRoman(4); // -> IV
    printIntToRoman(9); // -> IX
    printIntToRoman(58); // -> LVIII
    printIntToRoman(1994); // -> MCMXCIV

    return 0;
}