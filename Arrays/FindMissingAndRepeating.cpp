class Solution{
public:
    int *findTwoElement(int *arr, long long n) {
        // code here
        long long arrSum=0;
        long long duplicate;
        long long missing;
        for(long long i=0;i<n;i++){
            arrSum+=(long long)arr[i];
        }
        long long simpleSum=n*(n+1)/2;
        long long arrSquSum=0;
        long long a=(arrSum-simpleSum);
        for(long long i=0;i<n;i++){
            arrSquSum+=((long long)arr[i]*(long long)arr[i]);
        }
        long long squSum=n*(n+1)*(2*(n)+1)/6;
        long long b=(arrSquSum-squSum)/a;
        duplicate=(a+b)/2;
        missing=(b-a)/2;
        int *ans=new int[2];
        ans[0]=duplicate;
        ans[1]=missing;
        return ans;
        
    }
};


/* Another Solution
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int * a= new int[2];
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
            else{
                a[0]=abs(arr[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(arr[i-1]>0){
                a[1]=i;
                break;
            }
        }
        return a;
    }
};
*/
