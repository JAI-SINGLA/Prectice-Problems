class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a=headA;
        ListNode*b=headB;
        int count=0;
        while(a!=b){
            if(count==2){
                break;
            }
            if(a==NULL){
                a=headB;
                count++;
            }
            else if(b==NULL){
                b=headA;
            }
            else{
                a=a->next;
                b=b->next;
            }
        }
        if(count==2){
            return NULL;
        }
        return b;
    }
};
