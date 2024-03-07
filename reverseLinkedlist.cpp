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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode temp(0);
        temp.next = head;

        ListNode* prev =&temp;

       
        //Navigate to the start of the reversal segment
        for(int i=0;i<left-1;i++)
        {
            prev = prev->next;
        }
        //start reversing from this node
        ListNode* const start = prev;
        ListNode* current = prev->next;
        ListNode* next = nullptr;
        
        //reverse the segment
        for (int i=0; i<right-left+1;i++){
            next = current->next;
            current->next = prev;
            prev =current;
            current = next;

        }
        //reconnect the reversed segment
        start->next->next = current;
        start->next = prev;

        return temp.next;
    }
};