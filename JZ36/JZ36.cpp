/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return nullptr;
        }

        ListNode* publicNode = nullptr;

        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while (true) {
            if (p1 == p2) {
                publicNode = p1;

                break;
            }
            else {
                p1 = p1->next;
                p2 = p2->next;

                if (p1 != p2) {
                    if (p1 == nullptr) {
                        p1 = pHead2;
                    }
                    if (p2 == nullptr) {
                        p2 = pHead1;
                    }
                }
            }
        }

        return publicNode;
    }
};