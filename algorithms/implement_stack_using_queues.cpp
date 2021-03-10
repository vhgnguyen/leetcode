#include "helper.h"
#include <queue>

using namespace helper;

class MyStack {

private:
    queue<int> que;

public:
    /** Initialize your data structure here. */
    MyStack() {
        cout << "null ";
    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for (int i = 1; i < que.size(); ++i) {
            que.push(que.front());
            que.pop();
        }
        cout << "null ";
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = que.front();
        que.pop();
        cout << top << " ";
        return top;
    }

    /** Get the top element. */
    int top() {
        cout << que.front() << " ";
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        cout << bool2str(que.empty());
        return que.empty();
    }
};


int main(int argc, char ** argv) {
    cout << "Input : [MyStack, push, push, top, pop, empty]" << endl;
    cout << "Output: [";
    MyStack mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.top(); // 2
    mystack.pop(); // 2
    mystack.empty(); // false
    cout << "]" << endl << printEnd() << endl; // Output: [null, null, null, 2, 2, false]

    return 0;
}