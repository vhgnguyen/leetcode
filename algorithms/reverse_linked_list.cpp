#include "helper.h"

using namespace Node;
using namespace helper;

ListNode* reverseList(ListNode* head) {
    ListNode* nextNode, *currNode = NULL;
    while (head) {
        nextNode = head->next;
        head->next = currNode;
        currNode = head;
        head = nextNode;
    }
    return currNode;
}

void printResult(vector<int> a) {
    ListNode* head = createListNode(a);
    cout << "Input: head = " << printListNode(head) << endl;
    cout << "Output: " << printListNode(reverseList(head)) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,3,4,5}); // Output: [5,4,3,2,1]
    printResult(vector<int>{1,2}); // Output: [2,1]

    return 0;
}