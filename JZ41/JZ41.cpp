// S2: Sum table
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ANS;

        vector<int> allSequence(ceil((double)sum / 2));        // ceil(): upper margin; floor(): lower margin
        vector<int> sumTable(ceil((double)sum / 2));
        int nowSum = 0;
        for (int i = 0; i < ceil((double)sum / 2); i++) {
            nowSum += i + 1;
            sumTable[i] = nowSum;

            allSequence[i] = i + 1;
        }

        for (int i = 1; i < sumTable.size(); i++) {        // start from sum(1 -> 2)
            if (sumTable[i] < sum) {
                continue;
            }
            else if (sumTable[i] == sum) {
                // Save sum
                vector<int> saveSequence(allSequence.begin(), allSequence.begin() + i + 1);        // sum(1, allSequence[i])
                ANS.push_back(saveSequence);
            }
            else {
                for (int j = 0; j < sumTable.size(); j++) {     // start from sum(1)
                    int tempSum = sumTable[i] - sumTable[j];
                    if (tempSum < sum) {
                        break;
                    }
                    else if (tempSum == sum) {
                        vector<int> saveSequence(allSequence.begin() + j + 1, allSequence.begin() + i + 1);        // sum(allSequence[j + 1], allSequence[i])
                        ANS.push_back(saveSequence);
                    }
                    else {
                        continue;
                    }
                }
            }
        }

        return ANS;
    }
};


// S3: Sliding window
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ANS;

        vector<int> allSequence(ceil((double)sum / 2));
        for (int i = 0; i < allSequence.size(); i++) {
            allSequence[i] = i + 1;
        }

        int nowSum = allSequence[0] + allSequence[1];
        for (int i = 0, j = 1; i < allSequence.size() && j < allSequence.size();) {
            if (nowSum < sum) {
                j++;
                if (j == allSequence.size()) {
                    break;
                }
                else {
                    nowSum += allSequence[j];
                }
            }
            else if (nowSum == sum) {
                vector<int> tempSequence(allSequence.begin() + i, allSequence.begin() + j + 1);

                ANS.push_back(tempSequence);

                nowSum -= allSequence[i];
                i++;
            }
            else {
                nowSum -= allSequence[i];
                i++;
            }
        }

        return ANS;
    }
};