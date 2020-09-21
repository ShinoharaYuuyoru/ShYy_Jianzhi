class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for (int i = 0; i < length;) {
            if (numbers[i] == i) {        // The number is at the right place
                i++;
            }
            else {        // Do swap
                if (numbers[i] != numbers[numbers[i]]) {
                    int temp = numbers[numbers[i]];
                    numbers[numbers[i]] = numbers[i];
                    numbers[i] = temp;
                }
                else {
                    *duplication = numbers[i];
                    return true;
                }
            }
        }

        return false;
    }
};