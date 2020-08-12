// S1: priority_queue
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ANS;
        priority_queue<int, vector<int>, less<int> > Q;

        if (input.empty() == true) {
            return ANS;
        }
        if (k > input.size()) {
            return ANS;
        }

        for (int i = 0; i < input.size(); i++) {
            int curr = input[i];
            Q.push(curr);
            if (Q.size() > k) {
                Q.pop();
            }
        }

        while (Q.empty() == false) {
            ANS.push_back(Q.top());
            Q.pop();
        }

        return ANS;
    }
};


// S2: Maintain a size-k vector with maxVal.
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ANS;
        int max = INT_MIN;

        if (input.empty() == true) {
            return ANS;
        }
        if (k > input.size()) {
            return ANS;
        }

        for (int i = 0; i < input.size(); i++) {
            if (ANS.size() < k) {
                ANS.push_back(input[i]);
                if (input[i] > max) {
                    max = input[i];
                }
            }
            else {
                if (input[i] >= max) {
                    continue;
                }
                else {
                    auto search = find(ANS.begin(), ANS.end(), max);
                    *search = input[i];
                    max = INT_MIN;
                    for (int j = 0; j < ANS.size(); j++) {
                        if (ANS[j] > max) {
                            max = ANS[j];
                        }
                    }
                }
            }
        }

        sort(ANS.begin(), ANS.end());

        return ANS;
    }
};


// S3: Write a heap... Omit.