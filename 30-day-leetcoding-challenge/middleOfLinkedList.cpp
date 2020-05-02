/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto current = head;
        auto next = head;
        while(next->next != nullptr)
        {
            current = current->next;
            next = next->next;
            if(next->next != nullptr)
            {
                next = next->next;
            }
        }
        return current;
    }
};