#include<stack>
using namespace std;
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        inStack.push(value);
    }
    
    int deleteHead() {
        if (outStack.empty()){
            if (inStack.empty()){
                return -1;
            }
            In2Out();
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }
private:
    stack<int> inStack, outStack;
    void In2Out(){
        while (!inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */