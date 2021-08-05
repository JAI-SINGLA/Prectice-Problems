//O(n) time and space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
        ListNode*temp=head;
        while(temp!=NULL){
            if(mp.count(temp)>0){
                return true;
            }
            mp[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};

/*O(1) space and O(n) time Solution

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
        
        
    }
};
*/
