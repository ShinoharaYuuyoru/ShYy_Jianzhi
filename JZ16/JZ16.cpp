/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/


// Plain solution
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return pHead1 == nullptr ? pHead2 : pHead1;
        }

        ListNode* newHead;
        ListNode* ptrL1 = pHead1;
        ListNode* ptrL2 = pHead2;
        if (ptrL1->val <= ptrL2->val) {
            newHead = ptrL1;
            ptrL1 = ptrL1->next;
        }
        else {
            newHead = ptrL2;
            ptrL2 = ptrL2->next;
        }

        ListNode* newListBuilder = newHead;
        while (true) {
            if (ptrL1 == nullptr || ptrL2 == nullptr) {
                newListBuilder->next = (ptrL1 == nullptr ? ptrL2 : ptrL1);

                break;
            }
            else {
                if (ptrL1->val <= ptrL2->val) {
                    newListBuilder->next = ptrL1;

                    ptrL1 = ptrL1->next;
                }
                else {
                    newListBuilder->next = ptrL2;

                    ptrL2 = ptrL2->next;
                }
                newListBuilder = newListBuilder->next;
            }
        }

        return newHead;
    }
};


// Recursive solution
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr) {
            return pHead2;
        }
        if (pHead2 == nullptr) {
            return pHead1;
        }

        if (pHead1->val <= pHead2->val) {
            pHead1->next = Merge(pHead1->next, pHead2);

            return pHead1;
        }
        else {
            pHead2->next = Merge(pHead1, pHead2->next);

            return pHead2;
        }
    }
};