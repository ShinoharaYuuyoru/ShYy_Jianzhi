class Solution {
public:
    void push(int value) 
        S.push(value);
        if (minS.empty() == true) {
            minS.push(value);
        }
        else {
            int nowMin = minS.top();
            if (value <= nowMin) {
                minS.push(value);
            }
        }
    }
    void pop() {
        int popVal = S.top();
        S.pop();
        if (popVal == minS.top()) {
            minS.pop();
        }
    }
    int top() {
        return S.top();
    }
    int min() {
        return minS.top();
    }

private:
    stack<int> S;
    stack<int> minS;
};