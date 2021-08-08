Node*merge(Node*root1,Node*root2){
    Node*fh=NULL;
    Node*ft=NULL;
    while(root1!=NULL && root2!=NULL){
        if(root1->data<root2->data){
            if(fh==NULL){
                fh=root1;
                ft=fh;
            }
            else{
                ft->bottom=root1;
                ft=root1;
            }
            root1=root1->bottom;
        }
        else{
             if(fh==NULL){
                fh=root2;
                ft=fh;
            }
            else{
                ft->bottom=root2;
                ft=root2;
            }
            root2=root2->bottom;
        }
    }
    while(root1!=NULL){
        if(fh==NULL){
                fh=root1;
                ft=fh;
            }
            else{
                ft->bottom=root1;
                ft=root1;
            }
            root1=root1->bottom;
        
    }
    while(root2!=NULL){
        if(fh==NULL){
                fh=root2;
                ft=fh;
            }
            else{
                ft->bottom=root2;
                ft=root2;
            }
            root2=root2->bottom;
    }
    ft->bottom=NULL;
    return fh;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root->next==NULL){
       return root;
   }
   Node*root1=flatten(root->next);
   root=merge(root1,root);
   return root;
}
