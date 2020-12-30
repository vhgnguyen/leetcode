#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

    /**
     * Solution: split A & B into two parts:
     *    left              right
     * A[0],...,A[i]  |  A[i+1],...,A[m-1]
     * B[0],...,B[j]  |  B[j+1],...,B[n-1]
     *  
     * which satisfies:
     *  len(left) = len(right)
     *  max(left) < min(right)
     * then the median of the merged array is (left+right)*0.5
     * 
     * Use binary search in [0,m] to find the index i in A which satisfied the aforementioned conditions
     * Since the binary search reduce the search range by half after each loop, the time complexity
     * is O(log(n)). And we only search in the smaller size array, so it is O( log(min(m,n)) ).
     * The number of stored variables is fixed, so space complexity is O(1)
     * 
     * Note:
     *  If m + n is even, then the median is the max(left)
     *  If m + n is odd, then the median is (max(left) + min(right)) / 2.0
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size(), n = nums2.size();

        // prevent negative search index
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0, r = m, half_size = (m + n + 1) / 2;

        while (l <= r) {
            int i = (l + r) / 2;
            int j = half_size - i;

            // decrease i if it is too big
            if (i && nums1[i-1] > nums2[j])
                r = i - 1;
            // increase i if it is too smal
            else if (i < m && nums1[i] < nums2[j-1])
                l = i + 1;
            // stop searching if i is found, separate into even and odd size cases
            else {
                int max_left = !i ? nums2[j-1] : (!j ? nums1[i-1] : max(nums1[i-1], nums2[j-1]));
                
                // even size, return the max from left
                if ((m + n) % 2)
                    return max_left;

                int min_right = i == m ? nums2[j] : (j == n ? nums1[i] : min(nums1[i], nums2[j]));

                return (max_left + min_right) * 0.5;
            }
        }

        return 0;
    }
};


int main(int argc, char ** argv) {

    int size1, size2, input;
    double result;
    vector<int> nums1, nums2;

    cout << "nums1.size(): ";
    cin >> size1;
    while (size1 <0) {
        cout << "nums1.size() >= 0!" << endl;
        cout << "nums1.size(): ";
        cin >> size1;
    }
    while (nums1.size() < size1) {
        cout << "nums1[" << nums1.size() << "]: ";
        cin >> input;
        nums1.push_back(input);
    }

    cout << "nums2.size(): ";
    cin >> size2;
    while (size2 <0) {
        cout << "nums2.size() >= 0!" << endl;
        cout << "nums2.size(): ";
        cin >> size2;
    }
    while (nums2.size() < size2) {
        cout << "nums2[" << nums2.size() << "]: ";
        cin >> input;
        nums2.push_back(input);
    }

    cout << "Input : " << endl << "nums1 = [ ";
    for (auto it = nums1.begin(); it != nums1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "]" << endl;

    cout << "nums2 = [ ";
    for (auto it = nums2.begin(); it != nums2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "]" << endl;
  
    Solution sol;
    result = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Output: " << result << endl;
    
    return 0;
}