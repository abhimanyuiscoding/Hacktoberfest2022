class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left_head=new ListNode(0);
        ListNode *right_head=new ListNode(0);
        
        ListNode *left =left_head, *right=right_head;
        while(head){
            if(head->val<x){
                left->next=head;
                left=left->next;
            }
            else{
                right->next=head;
                right=right->next;
            }
            head=head->next;
        }
        right->next=NULL;
        left->next=right_head->next;
        return left_head->next;
        
    }
};
