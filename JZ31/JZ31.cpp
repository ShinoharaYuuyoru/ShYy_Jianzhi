// S2: Recursion
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        return f(n);
    }

private:
    int f(int n) {
        if (n <= 0) {
            return 0;
        }

        string s = to_string(n);
        int high = s[0] - '0';
        int p = pow(10, s.size() - 1);
        int last = n - high * p;

        if (high == 1) {
            return f(p - 1) + (last + 1) + f(last);
        }
        else {
            return high * f(p - 1) + p + f(last);
        }
    }
};


// S3: Find the pattern
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ANS = 0;

        int digit = 1;
        int high = n / 10;
        int cur = n % 10;
        int low = 0;

        while (high != 0 || cur != 0) {
            if (cur == 0) {
                ANS += high * digit;
            }
            else if (cur == 1) {
                ANS += high * digit + (low + 1);
            }
            else {
                ANS += (high + 1) * digit;
            }

            low += cur * digit;
            cur = high % 10;
            high = high / 10;
            digit = digit * 10;
        }

        return ANS;
    }
};