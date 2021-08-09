//O(n) time and space solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node*temp=head;
        while(temp!=NULL){
            Node*newNode=new Node(temp->val);
            mp[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            mp[temp]->next=mp[temp->next];
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
        
        
        
    }
};
//O(1) space solution (Brilliant One)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node*temp=head;
        while(temp!=NULL){
            Node*newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random=temp->random;
            }
            else{
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node*fh=NULL;
        fh=temp->next;
        while(temp!=NULL){
            Node*temp2=temp->next->next;
            if(temp2==NULL){
                temp->next->next=NULL;
            }
            else{
            temp->next->next=temp2->next;
            }
            temp->next=temp2;
            temp=temp2;
        }
        return fh;
        
    }
};
