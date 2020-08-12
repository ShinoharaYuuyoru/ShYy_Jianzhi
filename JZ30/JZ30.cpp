// S1: DP
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size());
        dp[0] = array[0];
        int ANS = array[0];
        for (int i = 1; i < array.size(); i++) {
            dp[i] = max(array[i], dp[i - 1] + array[i]);
            if (dp[i] > ANS) {
                ANS = dp[i];
            }
        }

        return ANS;
    }
};


// S2: Optimize to O(1) space.
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int dp = 0;
        dp = array[0];
        int ANS = array[0];
        for (int i = 1; i < array.size(); i++) {
            dp = max(array[i], dp + array[i]);
            if (dp > ANS) {
                ANS = dp;
            }
        }

        return ANS;
    }
};


// S3: Non-dp
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ANS = array[0];
        int temp = 0;

        for (int i = 0; i < array.size(); i++) {
            if (temp + array[i] < 0) {
                temp = 0;
            }
            else {
                temp += array[i];
            }
            ANS = (temp > ANS) ? temp : ANS;
        }

        if (temp == 0) {        // All numbers are negative.
            return *max_element(array.begin(), array.end());
        }
        else {
            return ANS;
        }
    }
};