#include "helper.h"

using namespace std;
using namespace helper;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    while (n) {
        nums1[m+n] = (m>0 && nums1[m-1] > nums2[n-1]) ? nums1[--m] : nums2[--n];
    }
}

void printResult(vector<int> nums1, int m, vector<int> nums2, int n) {
    cout << "Input: nums1 = " << v2s(nums1) << ", m = " << m << ", nums2 = " << v2s(nums2) << ", n = " << n << endl;
    merge(nums1, m, nums2, n);
    cout << "Output: " << v2s(nums1) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,3,0,0,0}, 3, vector<int>{2,5,6}, 3); // Output: [1,2,2,3,5,6]
    printResult(vector<int>{1}, 1, vector<int>{}, 0); // Output: [1]

    return 0;
}