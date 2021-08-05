class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*fh=NULL;
        ListNode*ft=NULL;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                if(fh==NULL){
                    fh=l1;
                    ft=l1;
                }
                else{
                  ft->next=l1;
                    ft=l1;
                }
                l1=l1->next;
            }
            else{
                 if(fh==NULL){
                    fh=l2;
                    ft=l2;
                }
                else{
                  ft->next=l2;
                    ft=l2;
                }
                l2=l2->next;
            }
        }
        while(l1!=NULL){
            if(fh==NULL){
                fh=ft=l1;
            }
            else{
            ft->next=l1;
            ft=l1;}
            l1=l1->next;
        }
        while(l2!=NULL){
            if(fh==NULL){
                fh=ft=l2;
            }
            else{
            ft->next=l2;
            ft=l2;}
            l2=l2->next;
        }
        return fh;
        
        
    }
};
