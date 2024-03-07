/*

Use 2 pointers slow & fast to detect the cycle. Floyd's Algorithm
(Tortoise and Hare Algorithm)

*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head||!head->next || !head->next->next) 
            return 0;
        ListNode *fast=head, *slow=head;
        //int i=0;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        //    cout<<++i<<",";
            if (fast==slow) return 1;
        }
        return 0;
    }

///2nd Code slow with stride=2 and fast with stride=3
  bool hasCycle(ListNode *head) {
        if (!head||!head->next || !head->next->next) 
            return 0;
        ListNode *fast=head, *slow=head;
        //int i=0;
        while(fast && fast->next && fast->next->next){
            fast=fast->next->next->next;
            slow=slow->next->next;
        //    cout<<++i<<",";
            if (fast==slow) return 1;
        }
        return 0;
    }