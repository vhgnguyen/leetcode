/*
 * @Author: Vo Hoang Nguyen
 * @Date:   2021-01-13 20:12:38
 * @Last Modified by:   Vo Hoang Nguyen
 * @Last Modified time: 2021-01-13 20:54:23
 */
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    ListNode* res = new ListNode(-1);
    ListNode* head = res;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            head->next = l1;
            l1 = l1->next;
        }
        else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    head->next = l1 == NULL ? l2 : l1;
    return res->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if (n == 0)
        return NULL;

    while (n>1) {
        for (int i = 0; i < n/2; ++i) {
            lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
        }
        n = (n+1) / 2;
    }
    return lists.front();
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

void printMergeKSortedLists(vector<vector<int>> v) {

    vector<ListNode*> vl{};
    for (auto & vi : v) {
        ListNode* l = createListNode(vi);
        vl.push_back(l);
    }

    ListNode* result = mergeKLists(vl);
    ListNode* tmp = result;

    cout << "Output: [";
    while (tmp != nullptr) {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << "]" << endl << "=======" << endl;
}


int main(int argc, char **argv) {

    printMergeKSortedLists(vector<vector<int>> {{1,4,5},{1,3,4},{2,6},{4,5}}); //Output: [1,1,2,3,4,4,5,6]
    printMergeKSortedLists(vector<vector<int>> {}); //Output: []
    printMergeKSortedLists(vector<vector<int>> {{}}); //Output: []

    return 0;
}