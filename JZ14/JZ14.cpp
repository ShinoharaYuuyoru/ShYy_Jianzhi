/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/


// S1: Easy way
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* ptr = pListHead;

        unsigned int total = 0;
        for (; ptr != nullptr; ptr = ptr->next) {
            total++;
        }

        if (k > total) {
            return nullptr;
        }

        ptr = pListHead;
        unsigned int cnt = total - k + 1;
        for (int i = 1; i < cnt; i++) {
            ptr = ptr->next;
        }

        return ptr;
    }
};


// S2: Two pointers
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr) {
            return nullptr;
        }

        ListNode* prePtr = pListHead;
        ListNode* rearPtr = pListHead;

        for (int i = 1; i <= k; i++) {
            rearPtr = rearPtr->next;

            if (rearPtr == nullptr && i < k) {
                return nullptr;
            }
        }

        for (; rearPtr != nullptr;) {
            prePtr = prePtr->next;
            rearPtr = rearPtr->next;
        }

        return prePtr;
    }
};