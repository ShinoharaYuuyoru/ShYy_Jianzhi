class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<pair<int, int>> mapping(52);        // first: counter; second: finalIndex

        for (int i = 0; i < str.size(); i++) {
            // diff = chara - 'A'(65) or 'a'(97)
            int diff = 0;
            if (str[i] <= 'Z') {
                // bigger case
                diff = str[i] - 'A';
            }
            else {
                // lower case
                diff = str[i] - 'a' + 26;
            }

            mapping[diff].first++;
            mapping[diff].second = i;
        }

        int onceOccurIndex = INT_MAX;
        for (int i = 0; i < mapping.size(); i++) {
            if (mapping[i].first == 1) {
                if (mapping[i].second < onceOccurIndex) {
                    onceOccurIndex = mapping[i].second;
                }
            }
        }

        return onceOccurIndex == INT_MAX ? -1 : onceOccurIndex;
    }
};