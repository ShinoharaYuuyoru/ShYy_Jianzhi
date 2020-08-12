// S1: Recursive
class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty() == true) {
            return ANS;
        }

        myPermutation(str, 0);
        sort(ANS.begin(), ANS.end());

        return ANS;
    }

    void myPermutation(string str, int begin) {
        if (begin == str.size()) {
            ANS.push_back(str);
            return;
        }

        for (int i = begin; i < str.size(); i++) {
            if (i != begin && str[i] == str[begin]) {
                continue;
            }

            swap(str[begin], str[i]);
            myPermutation(str, begin + 1);
            swap(str[begin], str[i]);
        }
    }

private:
    vector<string> ANS;
};


// S2: C++: next_permutation()
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ANS;
        if (str.empty() == true) {
            return ANS;
        }

        sort(str.begin(), str.end());
        ANS.push_back(str);
        while (next_permutation(str.begin(), str.end())) {
            ANS.push_back(str);
        }

        return ANS;
    }
};