class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) {
            return 0;
        }

        vector<int> result(index);
        result[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;        // Three pointers
        for (int i = 1; i < index; i++) {
            result[i] = min(result[p2] * 2, min(result[p3] * 3, result[p5] * 5));
            if (result[i] == result[p2] * 2) {
                p2++;
            }
            if (result[i] == result[p3] * 3) {
                p3++;
            }
            if (result[i] == result[p5] * 5) {
                p5++;
            }
        }

        return result.back();
    }
};