class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> print;
        if (matrix.empty() == true) {
            return print;
        }

        // Bounds
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int left = 0;
        // Each loop walks 1 round.
        while (true) {
            // Top bound
            for (int ptr = left; ptr <= right; ptr++) {
                print.push_back(matrix[top][ptr]);
            }
            top++;
            // Exit
            if (top > bottom) {
                break;
            }

            // Right bound
            for (int ptr = top; ptr <= bottom; ptr++) {
                print.push_back(matrix[ptr][right]);
            }
            right--;
            // Exit
            if (left > right) {
                break;
            }

            // Bottom bound
            for (int ptr = right; ptr >= left; ptr--) {
                print.push_back(matrix[bottom][ptr]);
            }
            bottom--;
            // Exit
            if (top > bottom) {
                break;
            }

            // Left bound
            for (int ptr = bottom; ptr >= top; ptr--) {
                print.push_back(matrix[ptr][left]);
            }
            left++;
            // Exit
            if (left > right) {
                break;
            }
        }

        return print;
    }
};