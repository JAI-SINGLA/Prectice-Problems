class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0){
            return 0;
        }
        
        int currentStreak=1;
        int maxStreak=1;
        int i=1;
        while(i<nums.size()){
            if(nums[i]==nums[i-1]+1){
                currentStreak++;
                i++;
            }
            else if(nums[i]==nums[i-1]){
                i++;
            }
            else{
                currentStreak=1;
                i++;
            }
            maxStreak=max(currentStreak,maxStreak);
        }
        return maxStreak;
        
    }
};

/* O(n) Solution and no changes in original Array
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=1;
        }
        int i=0;
        int currentStreak=0;
        int maxStreak=0;
        while(i<nums.size()){
            if(mp.count(nums[i]-1)<=0){
                currentStreak=1;
                int temp=nums[i]+1;
                while(mp.count(temp)>0){
                    currentStreak++;
                    temp++;
                }
                maxStreak=max(maxStreak,currentStreak);
            }
            i++;
        }
        return maxStreak;
        
    }
};
*/
