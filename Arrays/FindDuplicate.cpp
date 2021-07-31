class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])>0){
                return nums[i];
            }
            mp[nums[i]]=1;
        }
        return -1;
       
        
    }
};
/* O(1) Space Solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
           if(nums[abs(nums[i])-1]>0){
               nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
           }
           else{
               return abs(nums[i]);
           }
       }
        return -1;
       
        
    }
};
*/
/*Cycle Detection Approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];
        do{
            fast=nums[nums[fast]];
            slow=nums[slow];
        }while(slow!=fast);
        fast=nums[0];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};
*/
