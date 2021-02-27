#include <stack>
#include <algorithm>
#include "helper.h"

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> m;

public:
    /** initialize your data structure here. */
    MinStack() {
        cout << "null ";
    }

    ~MinStack() {

    }
    
    void push(int x) {
        if (m.empty())
            m.push({x, x});
        else
            m.push({x, min(m.top().second, x)});
        cout << "null ";
    }
    
    void pop() {
        m.pop();
        cout << "null ";
    }
    
    int top() {
        cout << m.top().first << " ";
        return m.top().first;
    }
    
    int getMin() {
        cout << m.top().second << " ";
        return m.top().second;
    }
};


int main(int argc, char ** argv) {

    cout << "Input : [MinStack,push(-2),push(0),push(-3),getMin(),pop(),top(),getMin()]" << endl;
    cout << "Output: [";
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // -3
    minStack.pop();
    minStack.top();    // 0
    minStack.getMin(); // -2
    cout << "]" << endl << helper::printEnd() << endl; // Output: [null,null,null,null,-3,null,0,-2]

    return 0;
}