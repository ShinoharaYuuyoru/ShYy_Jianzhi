class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        int res = 0;
        for (int num : data) {
            res ^= num;
        }

        *num1 = 0;
        *num2 = 0;

        res = res & (-res);
        for (int num : data) {
            if (num & res) {
                *num1 ^= num;
            }
            else {
                *num2 ^= num;
            }
        }
    }
};