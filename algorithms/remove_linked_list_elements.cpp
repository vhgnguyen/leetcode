#include "helper.h"

using namespace Node;
using namespace helper;


ListNode* removeElements(ListNode* head, int val) {
    ListNode** curr = &head;
    while (*curr) {
        if ((*curr)->val == val) {
            *curr = (*curr)->next;
        }
        else {
            curr = &(*curr)->next;
        }
    }
    return head;
}

void printResult(vector<int> a, int val) {
    ListNode* head = createListNode(a);
    cout << "Input: " << printListNode(head) << ", val = " << val << endl;
    head = removeElements(head, val);
    cout << "Output: " << printListNode(head) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,6,3,4,5,6}, 6); // Output: 1->2->3->4->5

    return 0;
}