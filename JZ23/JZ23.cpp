class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty() == true) {
            return false;
        }

        return isBST(sequence, 0, sequence.size() - 1);
    }

private:
    bool isBST(vector<int>& seq, int start, int end) {
        if (start >= end) {
            return true;
        }

        int val = seq[end];
        int split = start;
        for (; split < end && seq[split] < val; split++);

        // Check
        for (int i = split; i < end; i++) {
            if (seq[i] < val) {
                return false;
            }
        }

        return isBST(seq, start, split - 1) && isBST(seq, split, end - 1);
    }
};