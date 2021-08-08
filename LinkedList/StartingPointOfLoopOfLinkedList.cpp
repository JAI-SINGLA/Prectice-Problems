class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp=head;
        unordered_map<ListNode*,int>mp;
        while(temp!=NULL){
            if(mp.count(temp)>0){
                return temp;
            }
            mp[temp]=1;
            temp=temp->next;
        }
        return NULL;
        
        
    }
};


//O(1) Space solution
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        if(head==NULL || head->next==NULL){
                return NULL;
        }
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(fast!=slow && fast!=NULL && fast->next!=NULL );
        if(fast==NULL || fast->next==NULL){
            return NULL;
        }
        ListNode*temp=head;
        while(temp!=fast){
            temp=temp->next;
            fast=fast->next;
        }
        return fast;
    }
};
