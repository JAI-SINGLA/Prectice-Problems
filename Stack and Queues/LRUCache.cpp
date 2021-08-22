class Node{
    public:
    pair<int,int>p;
    Node*prev;
    Node*next;
    Node(pair<int,int>data){
        p.first=data.first;
        p.second=data.second;
        prev=next=NULL;
    }
};
class LRUCache {
public:
    Node*head;
    Node*tail;
    unordered_map<int,Node*>mp;
    int size;
    LRUCache(int capacity) {
        size=capacity;
        head=new Node({-1,0});
        tail=new Node({-1,0});
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.count(key)>0){
            Node*temp=mp[key];
            int val=temp->p.second;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            Node*newNode=new Node({key,val});
            newNode->next=head->next;
            newNode->prev=head;
            head->next->prev=newNode;
            head->next=newNode;
            mp[key]=newNode;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)>0){
            get(key);
            head->next->p.second=value;
            return;
        }
        Node*newNode=new Node({key,value});
        if(size==mp.size()){
            Node*temp=tail->prev;
            mp.erase(temp->p.first);
            temp->prev->next=tail;
            tail->prev=temp->prev;
            delete temp;
        }
        mp[key]=newNode;
        newNode->next=head->next;
        head->next->prev=newNode;
        newNode->prev=head;
        head->next=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
