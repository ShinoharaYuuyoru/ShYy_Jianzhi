class Solution {
public:
    int jumpFloorII(int number) {
        // f(n) = sigma(f(n-1) + ... + f(0))
        // f(n-1) = sigma(f(n-2) + ... + f(0))
        // -> f(n) = 2*f(n-1)

        vector<int> jump(number + 1);
        jump[0] = 0;
        jump[1] = 1;

        for (int i = 2; i <= number; i++) {
            jump[i] = jump[i - 1] * 2;
        }

        return jump[number];
    }
};