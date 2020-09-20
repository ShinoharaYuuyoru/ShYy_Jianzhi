class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty() == true) {
            return str;
        }

        int moveSize = n % str.size();
        return str.substr(n) + str.substr(0, n);
    }
};