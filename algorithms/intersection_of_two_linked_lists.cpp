#include "helper.h"

using namespace Node;
using namespace helper;


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    int ca = 0, cb = 0;
    while (a) {
        ca++;
        a = a->next;
    }
    while (b) {
        cb++;
        b = b->next;
    }
    int diff = ca - cb;
    if (diff < 0) {
        diff *= -1;
        swap(headA, headB);
    }
    while (diff--) {
        headA = headA->next;
    }
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

void test1() {
    //         (4) -> (1) _
    //                     (8) -> (4) -> (5)
    //  (5) -> (6) -> (1) / 

    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n8 = new ListNode(8, n4);
    ListNode* n1A = new ListNode(1, n8);
    ListNode* n1B = new ListNode(1, n8);
    ListNode* n4A = new ListNode(4, n1A);
    ListNode* n6B = new ListNode(6, n1B);
    ListNode* headA = new ListNode(1, n4A);
    ListNode* headB = new ListNode(1, n6B);

    cout << "Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1" << endl;
    ListNode* intersect = getIntersectionNode(headA, headB);
    string res = intersect ? to_string(intersect->val) : "null";
    cout << "Output: Reference of the node with value = " << res << endl << printEnd() << endl;
};

void test2() {
    //  (1) -> (9) -> (1) _
    //                     (2) -> (4)
    //                (3) / 

    ListNode* n4 = new ListNode(4);
    ListNode* n2 = new ListNode(2, n4);
    ListNode* n1A = new ListNode(1, n2);
    ListNode* n9A = new ListNode(9, n1A);
    ListNode* headA = new ListNode(1, n9A);
    ListNode* headB = new ListNode(3, n2);
    
    cout << "Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1" << endl;
    ListNode* intersect = getIntersectionNode(headA, headB);
    string res = intersect ? to_string(intersect->val) : "null";
    cout << "Output: Reference of the node with value = " << res << endl << printEnd() << endl;
};

void test3() {
    //  (1) -> (9) -> (1) 
    //                     
    //         (1) -> (5)

    ListNode* n1A = new ListNode(1);
    ListNode* n9A = new ListNode(9, n1A);
    ListNode* headA = new ListNode(1, n9A);

    ListNode* n5B = new ListNode(5);
    ListNode* headB = new ListNode(1, n5B);
    
    cout << "Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1" << endl;
    ListNode* intersect = getIntersectionNode(headA, headB);
    string res = intersect ? to_string(intersect->val) : "null";
    cout << "Output: Reference of the node with value = " << res << endl << printEnd() << endl;
};


int main(int argc, char ** argv) {
    
    test1(); // Output: 8
    test2(); // Output: 2
    test3(); // Output: null

    return 0;
}
