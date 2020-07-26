/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/


// S1: Easy way
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr) {
            return nullptr;
        }

        RandomListNode* newHead = new RandomListNode(pHead->label);
        RandomListNode* newPtr = newHead;

        RandomListNode* ptr = pHead->next;
        while (ptr != nullptr && ptr != pHead) {
            RandomListNode* newNode = new RandomListNode(ptr->label);
            newPtr->next = newNode;
            newPtr = newNode;

            ptr = ptr->next;
        }

        ptr = pHead;
        newPtr = newHead;
        while (ptr != nullptr) {
            if (ptr->random != nullptr) {
                RandomListNode* finder = pHead;
                RandomListNode* newFinder = newHead;
                while (finder != ptr->random) {
                    finder = finder->next;
                    newFinder = newFinder->next;
                }
                newPtr->random = newFinder;
            }

            ptr = ptr->next;
            newPtr = newPtr->next;
            if (ptr == pHead && newPtr == newHead) {
                break;
            }
        }

        return newHead;
    }
};


// S2: Use map(unordered_map)
#include <unordered_map>

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr) {
            return nullptr;
        }

        unordered_map<RandomListNode*, RandomListNode*> mapper;

        RandomListNode* ptr = pHead;
        while (true) {
            RandomListNode* newNode = new RandomListNode(ptr->label);
            mapper.insert({ ptr, newNode });

            ptr = ptr->next;
            if (ptr == nullptr || ptr == pHead) {
                break;
            }
        }

        ptr = pHead;
        while (true) {
            RandomListNode* node = mapper[ptr];
            node->next = (ptr->next != nullptr) ? mapper[ptr->next] : nullptr;
            node->random = (ptr->random != nullptr) ? mapper[ptr->random] : nullptr;

            ptr = ptr->next;
            if (ptr == nullptr || ptr == pHead) {
                break;
            }
        }

        return mapper[pHead];
    }
};


// S3: Inplace cloning and spliting
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr) {
            return nullptr;
        }

        // Inplace cloning.
        RandomListNode* ptr = pHead;
        while (true) {
            RandomListNode* cloneNode = new RandomListNode(ptr->label);

            RandomListNode* nextNode = ptr->next;
            ptr->next = cloneNode;
            cloneNode->next = nextNode;

            ptr = nextNode;
            if (ptr == nullptr || ptr == pHead) {
                break;
            }
        }

        // Clone random
        ptr = pHead;
        while (true) {
            ptr->next->random = (ptr->random != nullptr) ? ptr->random->next : nullptr;

            ptr = ptr->next->next;
            if (ptr == nullptr || ptr == pHead) {
                break;
            }
        }

        // Split
        ptr = pHead;
        RandomListNode* newHead = ptr->next;
        while (true) {
            RandomListNode* newNode = ptr->next;
            ptr->next = ptr->next->next;        // Cut
            newNode->next = (newNode->next != nullptr) ? newNode->next->next : nullptr;        // Split

            ptr = ptr->next;
            if (ptr == nullptr || ptr == pHead) {
                break;
            }
        }

        return newHead;
    }
};