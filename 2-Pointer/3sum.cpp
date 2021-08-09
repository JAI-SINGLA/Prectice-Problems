//TLE SOLUTION 
class Solution {
public:
    void addTriplet(vector<vector<int>>&ans,int num1,int num2,int num3){
        for(int i=0;i<ans.size();i++){
            if(ans[i][0]==num1 && ans[i][1]==num2 && ans[i][2]==num3){
                return;
            }
        }
        vector<int>v;
        v.push_back(num1);
        v.push_back(num2);
        v.push_back(num3);
        ans.push_back(v);
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans; 
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        addTriplet(ans,nums[i],nums[j],nums[k]);
                    }
                }
            }
        }
        return ans;
    }
};
//O(n2) Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>>ans;
        if(nums.size()<3){
            return ans;
        }
        while(i<nums.size()-2){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            i++;
            while(i<nums.size()-2 && nums[i]==nums[i-1]){
                i++;
            }
        }
        return ans;
    }
};
