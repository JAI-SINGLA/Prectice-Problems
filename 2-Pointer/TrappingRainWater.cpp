//O(n) Space solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);
        leftMax[0]=height[0];
        for(int i=1;i<height.size();i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        int ans=0;
        for(int i=1;i<height.size()-1;i++){
            ans+=(min(rightMax[i],leftMax[i])-height[i]);
        }
        return ans;
        
    }
};

//O(n) & O(1) Solution
class Solution {
public:
    int trap(vector<int>& height) {
        
        int r=height.size()-2;
        int l=1;
        int ans=0;
        int n=height.size();
        int leftMax=height[0];
        int rightMax=height[n-1];
        while(l<=r){
            if(leftMax<rightMax){
                int smallans=leftMax-height[l];
                if(smallans>0){
                    ans+=smallans;
                }
                leftMax=max(leftMax,height[l]);
                l++;
            }
            else{
                int smallans=rightMax-height[r];
                if(smallans>0){
                    ans+=smallans;
                }
                rightMax=max(rightMax,height[r]);
                    r--;
            }
        }
            return ans;
    }
};
