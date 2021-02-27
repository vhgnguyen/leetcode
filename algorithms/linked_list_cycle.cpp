#include "helper.h"

using namespace Node;
using namespace helper;

bool hasCycle(ListNode *head) {
    ListNode* slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
            return true;
    }
    return false;
}

void test1() {
    //  (3) -> (2) -> (0) -> (-4)-. 
    //          ^                 |
    //          |_________________|
    ListNode* n4 = new ListNode(-4);
    ListNode* n3 = new ListNode(0, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* head = new ListNode(3, n2);
    n4->next = n2;
    cout << "Input: head = [3,2,0,-4], pos = 1" << endl;
    cout << "Output: " << bool2str(hasCycle(head)) << endl << printEnd() << endl;
};

void test2() {
    //  (1) -> (2)-. 
    //   ^         |
    //   |_________|
    ListNode* n2 = new ListNode(2);
    ListNode* head = new ListNode(1, n2);
    n2->next = head;
    cout << "Input: head = [1,2], pos = 0" << endl;
    cout << "Output: " << bool2str(hasCycle(head)) << endl << printEnd() << endl;
};

void test3() {
    //  (1)
    ListNode* head = new ListNode(1);
    cout << "Input: head = [1], pos = -1" << endl;
    cout << "Output: " << bool2str(hasCycle(head)) << endl << printEnd() << endl;
};

int main(int argc, char ** argv) {
    
    test1(); // Output: true
    test2(); // Output: true
    test3(); // Output: false

    return 0;
}
