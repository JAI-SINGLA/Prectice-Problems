int maxLen(int A[], int n)
{
    unordered_map<int,int>mp;
    int length=0;
    int max_length=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0){
            max_length=i+1;
        }
        if(mp.count(sum)>0){
            length=i-mp[sum];
            max_length=max(max_length,length);
        }
        else{
            mp[sum]=i;
        }
        
    }
    return max_length;
    // Your code here O(n) & O(n)
}
