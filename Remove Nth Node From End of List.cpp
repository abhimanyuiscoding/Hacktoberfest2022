    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head,*fast=head;
        while(n-->0){
            fast=fast->next;
        }
        if(fast==NULL) return head->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete(temp);
        return head;
    }
