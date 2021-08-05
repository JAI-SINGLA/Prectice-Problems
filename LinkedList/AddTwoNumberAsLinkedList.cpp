class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*l3=NULL;
        ListNode*lt=NULL;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            int num=l1->val+l2->val+carry;
            l1=l1->next;
            l2=l2->next;
                carry=0;
            if(num>=10){
                carry=1;
            }
            if(l3==NULL){
                l3=new ListNode(num%10);
                lt=l3;
            }
            else{
                lt->next=new ListNode(num%10);
                lt=lt->next;
            }
            
        }
        while(l1!=NULL){
            int num=l1->val+carry;
            l1=l1->next;
            carry=0;
            if(num>=10){
                carry=1;
            }
             if(l3==NULL){
                l3=new ListNode(num%10);
                lt=l3;
            }
            else{
                lt->next=new ListNode(num%10);
                lt=lt->next;
            }
            
        }
        while(l2!=NULL){
           int num=l2->val+carry;
            l2=l2->next;
            carry=0;
            if(num>=10){
                carry=1;
            }
             if(l3==NULL){
                l3=new ListNode(num%10);
                lt=l3;
            }
            else{
                lt->next=new ListNode(num%10);
                lt=lt->next;
            } 
        }
        if(carry==1){
            lt->next=new ListNode(1);
        }
        return l3;
        
    }
};
