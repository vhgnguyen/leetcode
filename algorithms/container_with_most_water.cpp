#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int maxArea(vector<int> & height) {

    int area = 0;
    int i = 0, j = height.size() - 1;

    while (i < j) {
        area = max(area, (j - i) * min(height[i], height[j]));
        height[i] < height[j] ? i++ : j--;
    }

    return area;
}

void printMaxArea(vector<int> height) {
    cout << "Input : " << "height = [ " << height[0];
    for (int i = 1; i < height.size(); ++i) {
        cout << "," << height[i];
    }
    cout << "]" << endl;
    int area = maxArea(height);
    cout << "Output: " << area << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printMaxArea(vector<int> {1,8,6,2,5,4,8,3,7});
    printMaxArea(vector<int> {1,1});
    printMaxArea(vector<int> {4,3,2,1,4});
    printMaxArea(vector<int> {1,2,1});

    return 0;   
}