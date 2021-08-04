class Solution {
public:
    int merge(vector<int>&nums,int l ,int m, int h){
        int *a=new int[h-l+1];
        int k=0;
        int s1=l;
        int s2=m+1;
        int ans=0;
        k=0;
        int j=m+1;
        for(int i=l;i<=m;i++){
            while(j<=h && nums[i]>2*(long long)nums[j]){
                j++;
            }
            ans+=(j-m-1);
        }
        while(s1<=m && s2<=h){
            if(nums[s1]>nums[s2]){
                a[k++]=nums[s2++];
            }
            else{
                a[k++]=nums[s1++];
            }
        }
        while(s1<=m){
            a[k++]=nums[s1++];
        }
        while(s2<=h){
            a[k++]=nums[s2++];
        }
        for(int i=0;i<k;i++){
            nums[i+l]=a[i];
        }
        return ans;
    
    }
    int reversePairs(vector<int>& nums, int l ,int h){
        if(l>=h)return 0;
        int mid=(l+h)/2;
        int a1=reversePairs(nums,l,mid);
        int a2=reversePairs(nums,mid+1,h);
        int a3=merge(nums,l,mid,h);
        return a1+a2+a3;
    }
    int reversePairs(vector<int>& nums) {
        return reversePairs(nums,0,nums.size()-1);
        
    }
};
