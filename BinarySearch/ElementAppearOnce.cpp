int uniqueElement(vector<int> arr, int n)
{
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    return ans;
}


//
int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int lo=0;
    int hi=n-2;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(arr[mid]==arr[mid^1]){
            lo=mid+1;
        }
        else{
            hi = mid-1;
        }
        
    }
    return arr[lo];
}
