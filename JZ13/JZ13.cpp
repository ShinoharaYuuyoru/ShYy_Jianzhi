// Extra vector
class Solution {
public:
    void reOrderArray(vector<int>& array) {
        vector<int> partitioned;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 1) {
                partitioned.push_back(array[i]);
            }
        }
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 0) {
                partitioned.push_back(array[i]);
            }
        }

        copy(partitioned.begin(), partitioned.end(), array.begin());
    }
};

// In-place O(n^2)
class Solution {
public:
    void reOrderArray(vector<int>& array) {
        for (int i = 0, j = 0; i < array.size() && j < array.size();) {
            if (array[j] % 2 == 1) {
                int temp = array[j];
                for (int k = j - 1; k >= i; k--) {
                    array[k + 1] = array[k];
                }
                array[i] = temp;

                i++;
                j++;
            }
            else {
                j++;
            }
        }
    }
};


// STL: stable_partition with lambda expression.
class Solution {
public:
    void reOrderArray(vector<int>& array) {
        stable_partition(array.begin(), array.end(), [](int x) { return x & 1; });
    }
};