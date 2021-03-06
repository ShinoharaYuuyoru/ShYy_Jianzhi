// S1: Easy way
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while (stack1.size() > 1) {
            int temp = stack1.top();
            stack2.push(temp);
            stack1.pop();
        }

        int retNum = stack1.top();
        stack1.pop();

        while (stack2.empty() == false) {
            int temp = stack2.top();
            stack1.push(temp);
            stack2.pop();
        }

        return retNum;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


// S2: Optimize
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int retNum = stack2.top();
        stack2.pop();
        return retNum;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};