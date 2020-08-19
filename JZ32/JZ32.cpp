class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strs;
        for (int val : numbers) {
            strs.push_back(to_string(val));
        }

        // Rewrite compare function. 4 methods. 
        // 1. Functor
        sort(strs.begin(), strs.end(), Com())

        // 2. Lambda (anonymous)
        sort(strs.begin(), strs.end(), [](string a, string b){
            return a + b < b + a;
        });

        // 3. Lambda (non-anonymous)
        auto lam = [](string a, string b){
            return a + b < b + a;
        };
        sort(strs.begin(), strs.end(), lam);

        // 4. Functional pointer
        sort(strs.begin(), strs.end(), comp);

        string ANS;
        for (string str : strs) {
            ANS += str;
        }

        return ANS;
    }

private:
    // 1. Functor
    struct Com {
        bool operator() (string a, string b) {
            return a + b < b + a;
        }
    };

    // 4. Functional pointer
    bool static comp(const string a, const string b) {
        return a + b < b + a;
    }
};