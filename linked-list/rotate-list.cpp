// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (!head || !head->next || k == 0) return head;

//         ListNode* p = head;
//         int cnt = 1;
//         while(p->next!= nullptr)
//         {
//             cnt++;
//             p = p->next;
//         }

//         k = k % cnt;
//         if (k == 0) return head;
        
//         p->next = head;

//         ListNode* newT = head;
//         for (int i = 0; i < cnt - k - 1; i++) {
//             newT = newT->next;
//         }

//         ListNode* newH = newT->next;
//         newT->next = nullptr;

//         return newH;
//     }
// };

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
        vector<ListNode*> v;
        auto p = head;
        while(p){
            v.push_back(p);
            p = p->next;
        }
        if(v.size() == 0 || k % v.size() == 0)
            return head;
        int n = k % v.size();
        v.back()->next = head;
        v[v.size() - n - 1]->next = 0;
        return v[v.size()-n];
    }
};