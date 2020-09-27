class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);
        if (A.size() == 0 || A.size() == 1) {
            return B;
        }

        int temp = 1;
        for (int i = 1; i < B.size(); i++) {
            temp = temp * A[i - 1];
            B[i] = temp;
        }

        temp = 1;
        for (int i = A.size() - 2; i >= 0; i--) {
            temp = temp * A[i + 1];
            B[i] = B[i] * temp;
        }

        return B;
    }
};