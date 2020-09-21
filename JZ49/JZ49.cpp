class Solution {
public:
    int StrToInt(string str) {
        if (str.empty() == true) {
            return 0;
        }

        int isNegative = 1;        // Set as positive number by default
        int value = 0;

        int idx = 0;
        // If there is a symbol
        if (str[0] == '-') {
            isNegative = -1;
            idx++;
        }
        else if (str[0] == '+') {
            isNegative = 1;
            idx++;
        }

        // If there is a symbol, idx == 1; else, idx == 0
        for (; idx < str.size(); idx++) {
            int digit = str[idx] - '0';
            if (digit < 0 || digit > 9) {        // Invalid input
                return 0;
            }

            /*
            * Original writing
            */
            //int overValue = isNegative * value - INT_MAX / 10;
            //if (overValue < 0) {
            //    value = value * 10 + isNegative * digit;
            //}
            //else if (overValue == 0) {
            //    if (isNegative == -1) {
            //        if (digit > 8) {
            //            return 0;
            //        }
            //        else {
            //            value = value * 10 + isNegative * digit;
            //        }
            //    }
            //    else if (isNegative == 1) {
            //        if (digit > 7) {
            //            return 0;
            //        }
            //        else {
            //            value = value * 10 + isNegative * digit;
            //        }
            //    }
            //    else {
            //        cout << "isNegative value error!" << endl;
            //        exit(1);
            //    }
            //}
            //else {        // Overflow
            //    return 0;
            //}

            /*
            * Optimized writing
            */
            int overValue = isNegative * value - INT_MAX / 10 + (((isNegative + 1) / 2 + digit > 8) ? 1 : 0);
            if (overValue > 0) {        // Overflow
                return 0;
            }
            else {        // Casual case
                value = value * 10 + isNegative * digit;
            }
        }

        return value;
    }
};