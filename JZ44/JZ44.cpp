// S1: Manual
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty() == true) {
            return str;
        }

        string ANS;
        auto space = find(str.begin(), str.end(), ' ');
        if (space == str.end()) {        // If there is no space.
            return str;
        }
        else {
            vector<string> wordList;
            for (int i = 0, j = 1; i < str.size() && j < str.size(); ) {
                if (j == str.size() - 1) {        // Final word
                    string word(str.begin() + i, str.begin() + j + 1);
                    wordList.push_back(word);

                    break;
                }
                else {
                    if (str[j] == ' ') {
                        string word(str.begin() + i, str.begin() + j);
                        wordList.push_back(word);

                        j++;
                        i = j;
                    }
                    else {
                        j++;
                    }
                }
            }

            for (int i = wordList.size() - 1; i >= 0; i--) {
                if (i == 0) {
                    ANS += wordList[i];
                }
                else {
                    ANS += wordList[i];
                    ANS += ' ';
                }
            }
        }

        return ANS;
    }
};


// S2: stringstream
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty() == true) {
            return str;
        }

        int i = 0;
        for (i = 0; i < str.size() && str[i] == ' '; i++);        // Case: str is full of spaces
        if (i == str.size()) {
            return str;
        }

        istringstream iss(str);
        vector<string> wordList;
        string word;
        while (iss >> word) {        // stringstream will strip a word by spaces.
            wordList.push_back(word);
        }

        ostringstream oss;
        for (int i = wordList.size() - 1; i >= 0; i--) {
            if (i == 0) {
                oss << wordList[i];
            }
            else {
                oss << wordList[i] << ' ';
            }
        }

        return oss.str();
    }
};