class Solution {
public:
    int Add(int num1, int num2)
    {
        int result = 0;
        int carry = 0;
        while (true) {
            result = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = result;
            num2 = carry;

            if (carry == 0) {
                break;
            }
        }

        return result;
    }
};