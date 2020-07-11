// O(32)
class Solution {
public:
    int  NumberOf1(int n) {
        int ANS = 0;
        int scanner = 0x01;
        while (scanner != 0) {
            if ((n & scanner) != 0) {
                ANS++;
            }

            scanner <<= 1;
        }

        return ANS;
    }
};


// O(num_of_one)
class Solution {
public:
    int  NumberOf1(int n) {
        int ANS = 0;
        int num = n;
        while (num != 0) {
            ANS++;

            num = num & (num - 1);
        }

        return ANS;
    }
};