class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.size() != 5) {
            return false;
        }

        set<int> S;
        int maxNum = 0;
        int minNum = 14;
        for (int number : numbers) {
            if (number > 0) {
                if (S.find(number) == S.end()) {
                    S.insert(number);
                    maxNum = max(maxNum, number);
                    minNum = min(minNum, number);
                }
                else {
                    return false;
                }
            }
        }

        return (maxNum - minNum) < 5;
    }
};