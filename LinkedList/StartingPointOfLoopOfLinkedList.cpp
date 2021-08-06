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
