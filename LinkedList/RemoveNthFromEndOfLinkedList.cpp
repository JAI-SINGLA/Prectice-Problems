class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int deleteNode=count-n+1;
        if(deleteNode<=0 || n<=0){
            return head;
        }
        temp=head;
        ListNode*prev=NULL;
        if(deleteNode==1){
            head=temp->next;
            delete temp;
            return head;
        }
        while(deleteNode!=1){
            prev=temp;
            temp=temp->next;
            deleteNode--;
        }
        prev->next=temp->next;
        delete temp;
        return head;
        
        
        
    }
};
