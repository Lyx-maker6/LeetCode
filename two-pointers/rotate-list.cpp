/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* p = head;
        int cnt = 1;
        while(p->next!= nullptr)
        {
            cnt++;
            p = p->next;
        }

        k = k % cnt;
        if (k == 0) return head;
        
        p->next = head;

        ListNode* newT = head;
        for (int i = 0; i < cnt - k - 1; i++) {
            newT = newT->next;
        }

        ListNode* newH = newT->next;
        newT->next = nullptr;

        return newH;
    }
};