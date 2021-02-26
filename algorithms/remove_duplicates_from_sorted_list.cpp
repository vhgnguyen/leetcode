#include "helper.h"
#include <algorithm>
#include <math.h>

using namespace std;
using namespace Node;
using namespace helper;

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cnode = head;
    while (cnode && cnode->next) {
        if (cnode->val == cnode->next->val) {
            cnode->next = cnode->next->next;
        }
        else {
            cnode = cnode->next;
        }
    }
    return head;
}

void printResult(vector<int> v) {
    cout << "Input: head = " << v2s(v) << endl;
    ListNode* head = createListNode(v);
    ListNode* res = deleteDuplicates(head);
    cout << "Output: " << printListNode(res) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,1,2,3,3}); // Output: [1,2,3]

    return 0;
}