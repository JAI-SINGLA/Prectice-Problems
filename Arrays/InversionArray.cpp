class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[],long long l, long long mid,long long h){
        long long s1=l;
        long long s2=mid+1;
        long long count=0;
        long long *temp=new long long[h-l+1];
        long long k=0;
        while(s1<=mid && s2<=h){
            if(arr[s1]>arr[s2]){
                count+=(mid-s1+1);
                temp[k++]=arr[s2++];
            }
            else{
                temp[k++]=arr[s1++];
            }
        }
        while(s1<=mid){
            temp[k++]=arr[s1++];
        }
        while(s2<=h){
            temp[k++]=arr[s2++];
        }
        for(long long i=0;i<k;i++){
            arr[i+l]=temp[i];
        }
        return count;
    }
    long long int inversionCount(long long arr[],long long l,long long h){
        if(h<=l){
            return 0;
        }
        long long mid=(l+h)/2;
        long long int a1=inversionCount(arr,l,mid);
        long long int a2=inversionCount(arr,mid+1,h);
        long long int a3=merge(arr,l,mid,h);
        return a1+a2+a3;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ans=inversionCount(arr,0,N-1);
        return ans;
    }

};
