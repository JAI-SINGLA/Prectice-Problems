class MyStack {
public:
    /** Initialize your data structure here. */
        queue<int>q1;
        queue<int>q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
        }
    
    /** Get the top element. */
    int top() {
        return q1.front();
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//Using a Single Queue
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int>q1;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
     q1.push(x);
        for(int i=1;i<q1.size();i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.size()==0?true:false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
