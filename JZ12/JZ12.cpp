// Brute force
class Solution {
public:
    double Power(double base, int exponent) {
        // Consider when n < 0
        if (exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }

        double ANS = 1.0;
        for (int i = 0; i < exponent; i++) {
            ANS = ANS * base;
        }

        return ANS;
    }
};


// Quick pow with recursive
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }

        return this->q_pow(base, exponent);
    }

private:
    double q_pow(double base, int exponent) {
        if (exponent == 0) {
            return 1.0;
        }

        double ret = q_pow(base, exponent / 2);
        if ((exponent & 1) == 1) {
            return ret * ret * base;
        }
        else {
            return ret * ret;
        }
    }
};


// Quick pow without recursive
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }

        double nowX = base;
        double ANS = 1.0;
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                ANS = ANS * nowX;
            }

            nowX = nowX * nowX;
            exponent = exponent >> 1;
        }

        return ANS;
    }
};