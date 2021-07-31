class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int gap=((n+m+1)/2);
    while(gap>=1){
        int i=0;
        int j=gap;
        while(j<m+n){
            if(j>=n &&i<n){
                if(arr1[i]>arr2[j-n]){
                    swap(arr1[i],arr2[j-n]);
                }
            }
            else if(i<n && j<n){
                if(arr1[i]>arr1[j]){
                    swap(arr1[i],arr1[j]);
                }
            }
            else{
                if(arr2[i-n]>arr2[j-n]){
                    swap(arr2[i-n],arr2[j-n]);
                }
            }
            i++;
            j++;
        }
        if(gap==1){
            break;
        }
        gap=(gap+1)/2;
        
    }
        } 
};



/* Another Mthod We Can Use by using modulo and maximum*/
