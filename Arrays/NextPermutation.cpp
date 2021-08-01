//We can return all the permutation and check which one is closer but tie ans space consuming
//o(n)solution 
class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        
        while(i>=0 &&nums[i]>=nums[i+1] ){
            i--;
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]>nums[i]){
                swap(nums[i],nums[j]);
                break;
                }
        }
        reverse(nums.begin()+i+1,nums.end());
        
    }
};
