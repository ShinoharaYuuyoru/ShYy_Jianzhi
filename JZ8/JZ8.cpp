class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp(number + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= number; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[number];
    }
};