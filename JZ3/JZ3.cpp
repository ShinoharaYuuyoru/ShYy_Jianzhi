/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;

        if (head == nullptr) {
            return array;
        }

        stack<int> S;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            int nowVal = ptr->val;
            S.push(nowVal);

            ptr = ptr->next;
        }

        while (S.empty() == false) {
            array.push_back(S.top());
            S.pop();
        }

        return array;
    }
};