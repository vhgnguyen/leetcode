#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


vector<int> findSubstring(string s, vector<string>& words) {

    int sl = s.length(), ws = words.size();
    if (sl == 0 || ws == 0)
        return {};

    vector<int> res;
    int wl = words[0].length(), left = 0, count_rep = 0;
    unordered_map<string, int> count, rep;

    // find occurence of each word
    for (auto & w : words)
        count[w]++;

    // number of sliding window equals length of a word
    for (int i = 0; i < wl; ++i) {
        rep.clear();

        // start position of sliding window
        left = i, count_rep = 0;

        // slide through string s with size of length of a word
        for (int j = i; j <= sl - wl; j += wl) {
            string w = s.substr(j, wl);
            // if a word matched
            if (count.count(w)) {
                rep[w]++;
                count_rep++;
                // remove all occurences from starting position
                // until equal the given occurence in vector
                // to prevent multiple repeat of a word
                while (rep[w] > count[w]) {
                    rep[s.substr(left, wl)]--;
                    count_rep--;
                    left += wl; // slide window in proportion to word length
                }
                if (count_rep == ws) 
                    res.push_back(left);
            }
            // slide window to next position
            else {
                rep.clear();
                count_rep = 0;
                left = j + wl;
            }
        }
    }
    return res;
}

void printResult(string s, vector<string> words) {
    cout << "Input: s = \"" << s << "\", words = [";
    for (int i = 0; i < words.size(); ++i) {
        cout << "\"" << words[i] << "\"";
        if (i != words.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    vector<int> res = findSubstring(s, words);
    cout << "Output: [";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult("barfoothefoobarman", vector<string> {"foo","bar"}); //Output: [0,9]
    printResult("wordgoodgoodgoodbestword", vector<string> {"word","good","best","word"}); //Output: []
    printResult("barfoofoobarthefoobarman", vector<string> {"bar","foo","the"}); //Output: [6,9,12]
 
    return 0;
}