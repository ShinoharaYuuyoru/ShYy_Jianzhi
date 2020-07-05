class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty() == true) {
            return 0;
        }
        if (rotateArray.size() == 1) {
            return rotateArray[0];
        }

        int retNum = 0;
        for (int i = 1; i < rotateArray.size(); i++) {
            if (rotateArray[i] > rotateArray[i - 1]) {
                continue;
            }
            else if (rotateArray[i] == rotateArray[i - 1]) {
                retNum = rotateArray[i];
                continue;
            }
            else {
                retNum = rotateArray[i];
                break;
            }
        }

        return retNum;
    }
};