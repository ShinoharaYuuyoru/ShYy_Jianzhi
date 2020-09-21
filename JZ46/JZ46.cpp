// S1: Circular linked list
typedef struct kid {
    int val;
    kid* next;

    kid(int val1) {
        val = val1;
        next = nullptr;
    }
}kid;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0) {
            return -1;
        }

        // Construct circular linked list
        kid* last = new kid(0);
        kid* head = last;
        for (int i = 1; i < n; i++) {
            kid* temp = new kid(i);
            last->next = temp;
            last = temp;
        }
        last->next = head;

        kid* pre = last;
        kid* now = head;
        int counter = 0;
        while (true) {
            if (now == pre) {
                break;
            }

            if (counter == m - 1) {
                kid* next = now->next;
                pre->next = next;
                delete(now);
                now = next;

                counter = 0;
            }
            else {
                counter++;
                now = now->next;
                pre = pre->next;
            }
        }

        return now->val;
    }
};


// S2: Recursion
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0) {
            return -1;
        }

        if (n == 1) {
            return 0;
        }

        return (LastRemaining_Solution(n - 1, m) + m) % n;
    }
};


// S3: Bottom-up
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0) {
            return -1;
        }

        int remain = 0;
        for (int i = 1; i <= n; i++) {
            remain = (remain + m) % i;
        }

        return remain;
    }
};