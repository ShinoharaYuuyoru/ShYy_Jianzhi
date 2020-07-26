class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() == true || popV.empty() == true || pushV.size() != popV.size()) {
            return false;
        }

        stack<int> S;
        int j = 0;
        for (int i = 0; i < pushV.size(); i++) {
            S.push(pushV[i]);

            while (S.empty() == false && popV[j] == S.top()) {
                S.pop();
                j++;
            }
        }

        return S.empty();
    }
};