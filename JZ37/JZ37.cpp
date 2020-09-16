class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty() == true) {
            return 0;
        }

        int leftMargin = binarySearchLeftMargin(data, k);
        int rightMargin = binarySearchRightMargin(data, k);
        if (leftMargin == -1 && rightMargin == -1) {
            return 0;
        }
        else {
            if (leftMargin == -1 || rightMargin == -1) {
                cout << "Binary search method error!" << endl;
                return -1;
            }
            else {
                return rightMargin - leftMargin + 1;
            }
        }
    }

private:
    int binarySearch(vector<int>& array, int target) {
        int left = 0;
        int right = array.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == target) {
                return mid;
            }
            else if (array[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int binarySearchLeftMargin(vector<int>& array, int target) {
        int left = 0;
        int right = array.size();

        while (left < right) {
            int mid = (left + right) / 2;
            if (array[mid] == target) {
                right = mid;
            }
            else if (array[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return array[left] == target ? left : -1;
    }

    int binarySearchRightMargin(vector<int>& array, int target) {
        int left = 0;
        int right = array.size();

        while (left < right) {
            int mid = (left + right) / 2;
            if (array[mid] == target) {
                left = mid + 1;
            }
            else if (array[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (left == 0) {
            return -1;
        }
        else {
            return array[left - 1] == target ? (left - 1) : -1;
        }
    }
};