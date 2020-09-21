class Solution {
public:
    int Sum_Solution(int n) {
        n >= 1 && (n += Sum_Solution(n - 1));

        return n;
    }
};