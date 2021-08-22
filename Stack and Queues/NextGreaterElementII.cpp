class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        vector<int>ans(nums.size());
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[i%nums.size()]>=s.top() ){
                s.pop();
            }
            if(i<nums.size()){
                if(s.empty()){
                     ans[i]=-1;
                }
                else{
                    ans[i]=s.top();                
                }
            }
            s.push(nums[i%nums.size()]);
        }
        return ans;
    }
};
