class Solution {
public:
    void replaceSpace(char* str, int length) {
        if (str == NULL || length < 0) {
            return;
        }

        int spaceNum = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                spaceNum++;
            }
        }
        int newLength = length + 2 * spaceNum;

        int oriStrPtr = length;
        int newStrPtr = newLength;
        while (oriStrPtr >= 0) {
            if (str[oriStrPtr] == ' ') {
                str[newStrPtr] = '0';
                str[newStrPtr - 1] = '2';
                str[newStrPtr - 2] = '%';
                newStrPtr -= 3;

                oriStrPtr--;
            }
            else {
                str[newStrPtr] = str[oriStrPtr];
                oriStrPtr--;
                newStrPtr--;
            }
        }

        return;
    }
};