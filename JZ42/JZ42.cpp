class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> ANS;

        for (int i = 0, j = array.size() - 1; i <= j;) {
            int nowSum = array[i] + array[j];
            if (nowSum < sum) {
                i++;
            }
            else if (nowSum == sum) {
                ANS.push_back(array[i]);
                ANS.push_back(array[j]);

                break;
            }
            else {
                j--;
            }
        }

        return ANS;
    }
};