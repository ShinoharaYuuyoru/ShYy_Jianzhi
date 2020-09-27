// S1: std::regex
#include <regex>

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        regex e(pattern);
        cmatch m;

        return (bool)regex_match(str, m, e);
    }
};


// S2: Reccursion
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        // Exit
        if (*str == '\0' && *pattern == '\0') {
            return true;
        }
        if (*str != '\0' && *pattern == '\0') {
            return false;
        }

        // Recursion
        if (*(pattern + 1) != '*') {        // pattern: ab
            if (*str != '\0' && (*str == *pattern || *pattern == '.')) {
                return match(str + 1, pattern + 1);
            }
            else {
                return false;
            }
        }
        else {        // pattern: a*
            bool retVal = false;

            // If there is more than 1 time duplicate in str
            if (*str != '\0' && (*str == *pattern || *pattern == '.')) {
                retVal = match(str + 1, pattern);
            }
            // If there is no duplicate in str
            // For the case aaa & a*a... we cannot write simply as if{} else{}.
            return retVal || match(str, pattern + 2);
        }
    }
};


// S3: DP
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int strSize = strlen(str);
        int patternSize = strlen(pattern);
        vector<vector<char> > f(strSize + 1, vector<char>(patternSize + 1, 0));

        for (int i = 0; i <= strSize; i++) {
            for (int j = 0; j <= patternSize; j++) {
                if (j == 0 && i == 0) {        // Initialize
                    f[i][j] = true;
                }
                else {
                    if (pattern[j - 1] != '*') {        // If there is no '*' in pattern
                        if (i >= 1 && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')) {
                            f[i][j] |= f[i - 1][j - 1];
                        }
                    }
                    else {
                        // Repeat once or more
                        if (i >= 1 && j >= 2 && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.')) {
                            f[i][j] |= f[i - 1][j];
                        }

                        // No repeatment
                        if (j >= 2) {
                            f[i][j] |= f[i][j - 2];
                        }
                    }
                }
            }
        }

        return (bool)f[strSize][patternSize];
    }
};