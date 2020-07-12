/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

// Easy way
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }

        stack<ListNode*> S;
        ListNode* ptr = pHead;
        while (ptr != nullptr) {
            S.push(ptr);
            ptr = ptr->next;
        }

        ListNode* newHead = S.top();
        S.pop();
        newHead->next = nullptr;
        ptr = newHead;
        while (S.empty() == false) {
            ListNode* temp = S.top();
            S.pop();
            ptr->next = temp;

            ptr = ptr->next;
            ptr->next = nullptr;
        }

        return newHead;
    }
};


// Three pointers
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }

        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        ListNode* rear = pHead->next;
        while (rear != nullptr) {
            cur->next = pre;

            pre = cur;
            cur = rear;
            rear = rear->next;
        }
        cur->next = pre;

        return cur;
    }
};