#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {

    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    ListNode *head = new ListNode(-1);
    ListNode *res = head;

    while (l1 && l2) {
        if (l1->val > l2->val) {
            head->next = l2;
            l2 = l2->next;
        }
        else {
            head->next = l1;
            l1 = l1->next;
        }
        head = head->next;
    }
    head->next = l1 == NULL ? l2 : l1;

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

void printMergeTwoLists(vector<int> v1, vector<int> v2) {

    ListNode* l1 = createListNode(v1);
    ListNode* l2 = createListNode(v2);

    cout << "Input: l1 = [";
    for (auto & i : v1) {
        cout << i << ",";
    }
    cout << "], " << "l2 = [";
    for (auto & i : v2) {
        cout << i << ",";
    }
    cout << "]";
    ListNode* result = mergeTwoLists(l1, l2);
    ListNode* tmp = result;

    cout << "Output: [";
    while (tmp != nullptr) {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << "]" << endl << "=======" << endl;
}


int main(int argc, char **argv) {

    printMergeTwoLists(vector<int>{1,2,4}, vector<int>{1,3,4}); //Output: [1,1,2,3,4,4]
    printMergeTwoLists(vector<int>{}, vector<int>{}); // Output: []
    printMergeTwoLists(vector<int>{}, vector<int>{0}); // Output: [0]

    return 0;
}