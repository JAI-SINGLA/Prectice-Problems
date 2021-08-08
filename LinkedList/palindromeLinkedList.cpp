class Solution {
    
public:
    bool isPalindrome(ListNode* head) {
        vector<ListNode*>vp;
        while(head!=NULL){
            vp.push_back(head);
            head=head->next;
        }
        int i=0;
        int j=vp.size()-1;
        while(i<j){
            if(vp[i]->val!=vp[j]->val){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

//O(1) space solution
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head->next;;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*head1=slow->next;
        ListNode*pre=NULL;
        ListNode*curr=head1;
            ListNode*next=curr->next;
            while(curr!=NULL){
                curr->next=pre;
                pre=curr;
                curr=next;
                if(next==NULL)break;
                next=next->next;
        }
        head1=pre;
        slow->next=head1;
        while(head1!=NULL){
            if(head->val!=head1->val)
                return false;
            head1=head1->next;
            head=head->next;
        }
        return true;
        
    }
};
//If want the list does not change then again find mid of list and again reverese it from mid to end.
