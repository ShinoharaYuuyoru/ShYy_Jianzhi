// S1: Hash to find the mode number.
#include <unordered_map>

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty() == true) {
            return 0;
        }

        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); i++) {
            auto search = hash.find(numbers[i]);
            if (search != hash.end()) {
                search->second++;
            }
            else {
                hash.insert(make_pair(numbers[i], 1));
            }
        }

        int ANS = 0;
        for (auto itr : hash) {
            if (itr.second > numbers.size() / 2) {
                ANS = itr.first;
                break;
            }
        }

        return ANS;
    }
};


// S2: Sort to find the mode number. Omit.


// S3: Counteract to find the number appearing over the half of the size.
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty() == true) {
            return 0;
        }

        int preVal = numbers[0];
        int cnt = 1;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == preVal) {
                cnt++;
            }
            else {
                cnt--;
                if (cnt == 0) {
                    preVal = numbers[i];
                    cnt = 1;
                }
            }
        }

        cnt = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == preVal) {
                cnt++;
            }
        }

        return (cnt > numbers.size() / 2) ? preVal : 0;
    }
};