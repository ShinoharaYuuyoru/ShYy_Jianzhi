class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0) {
            return false;
        }

        int N = array.size();
        int M = array[0].size();
        int minNum = array[0][0];
        int maxNum = array[N - 1][M - 1];
        if (target < minNum || target > maxNum) {
            return false;
        }
        else {
            for (int i = N - 1; i >= 0; i--) {
                if (array[i][0] > target) {
                    continue;
                }
                else if (array[i][0] == target) {
                    return true;
                }
                else {
                    if (binarySearch(array, i, target) == true) {
                        return true;
                    }
                    else {
                        continue;
                    }
                }
            }
        }

        return false;
    }

    bool binarySearch(vector<vector<int> >& array, int searchIndex, int target) {
        int left = 0;
        int right = array[searchIndex].size() - 1;
        for (; left <= right;) {
            int mid = (left + right) / 2;
            if (array[searchIndex][mid] < target) {
                left = mid + 1;
            }
            else if (array[searchIndex][mid] == target) {
                return true;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};