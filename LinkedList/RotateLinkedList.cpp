//O(n*k%n)solution
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL){
                return head;
            }
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        for(int i=1;i<=k%len;i++){
            ListNode*temp=head;
            ListNode*prev=NULL;
            while (temp->next!=NULL){
                prev=temp;
                temp = temp->next;
            }
            temp->next=head;
            prev->next=NULL;
            head=temp;
            
        }     
        return head;
    }
};

//O(n) solution
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*temp=head;
        int len=0;
        ListNode*pre=NULL;
        while(temp!=NULL){
            pre=temp;
            temp=temp->next;
            len++;
        }
        pre->next=head;
        k=len-(k%len);
        cout<<k;
        for(int i=1;i<k;i++){
            head=head->next;
        }
        ListNode*fh=head->next;
        head->next=NULL;
        return fh;
        
        
    }
};
