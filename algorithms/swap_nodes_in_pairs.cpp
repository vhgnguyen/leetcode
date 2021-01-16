#include <iostream>
#include <vector>
#include <string> 

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Recursive solution
 */
ListNode* swapPairs1(ListNode* head) {
    
    if (head == NULL || head->next == NULL) 
        return head;

    ListNode* res = head->next;
    head->next = swapPairs1(res->next);
    res->next = head;
    
    return res;
}

/**
 * Iterative solution
 * TODO: Since we replace head of res once, need put tmp1 = head out of while loop
 */
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) 
        return head;

    ListNode* res = new ListNode(-1), *tmp1, *tmp2;
    tmp1 = res;
    res->next = head;
    while (head && (tmp2 = head->next)) {
        head->next = tmp2->next;
        tmp2->next = head;
        tmp1->next = tmp2;
        tmp1 = head;
        head = tmp1->next;
    }
    return res->next;
}


/**
 * TEST FUNCTION
 * @brief Create a List Node object from vector
 * @param a 
 * @return ListNode* 
 */
ListNode* createListNode(vector<int> & a) {

    ListNode* r = NULL;
    ListNode* t = NULL;
    ListNode* p = NULL;

    for (int i = 0; i < a.size(); i++) {
        t = new ListNode(a[i]);
        if (i == 0) {
            r = t;
        }
        else {
            p->next = t;
        }
        p = t;
    }
    return r;
}

void printSwapPairs(vector<int> v) {

    ListNode* head = createListNode(v);
    cout << "Input: head = [";
    for (auto & i : v) {
        cout << i << ",";
    }
    cout << "]" << endl;

    ListNode* result = swapPairs(head);
    ListNode* tmp = result;

    cout << "Output: [";
    while (tmp != nullptr) {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << "]" << endl << "=======" << endl;
}


int main(int argc, char ** argv) {

    printSwapPairs(vector<int> {1,2,3,4}); // Output: [2,1,4,3]
    printSwapPairs(vector<int> {}); // Output: []
    printSwapPairs(vector<int> {1}); // Output: [1]

    return 0;
}