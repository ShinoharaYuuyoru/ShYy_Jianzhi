class Solution {
public:
    int InversePairs(vector<int> data) {
        mergeSort(data, 0, data.size() - 1);

        return ANS % 1000000007;
    }

    // Merge sort(acsending)
    void mergeSort(vector<int>& array, int left, int right) {
        // Exit
        if (left == right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }

    void merge(vector<int>& array, int left, int mid, int right) {
        vector<int> temp(right - left + 1);

        int b1Idx = left, b2Idx = mid + 1;        // 2-way merging. Block 1 and 2 indexes.
        int tempIdx = 0;
        while (b1Idx <= mid && b2Idx <= right) {
            // Here we will operate the counter.
            if (array[b1Idx] > array[b2Idx]) {
                ANS += mid - b1Idx + 1;
                ANS = ANS % 1000000007;

                temp[tempIdx] = array[b2Idx];
                tempIdx++;
                b2Idx++;
            }
            else {
                temp[tempIdx] = array[b1Idx];
                tempIdx++;
                b1Idx++;
            }

            // Original merge sort code.
            //temp[tempIdx] = array[b1Idx] <= array[b2Idx] ? array[b1Idx] : array[b2Idx];
            //tempIdx++;
            //b1Idx++;
            //b2Idx++;
        }
        while (b1Idx <= mid) {
            temp[tempIdx] = array[b1Idx];
            tempIdx++;
            b1Idx++;
        }
        while (b2Idx <= right) {
            temp[tempIdx] = array[b2Idx];
            tempIdx++;
            b2Idx++;
        }

        // Copy to original array.
        for (int i = 0; i < temp.size(); i++) {
            array[left + i] = temp[i];
        }
    }

private:
    int ANS = 0;
};