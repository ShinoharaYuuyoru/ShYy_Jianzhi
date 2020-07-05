class Solution {
public:
    int Fibonacci(int n) {
        vector<int> fibonacci;

        fibonacci.push_back(0);
        fibonacci.push_back(1);
        for (int i = 2; i <= n; i++) {
            int num = fibonacci[i - 1] + fibonacci[i - 2];
            fibonacci.push_back(num);
        }

        return fibonacci[n];
    }
};