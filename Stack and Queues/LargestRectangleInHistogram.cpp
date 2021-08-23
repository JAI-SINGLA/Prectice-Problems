class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int *leftSmaller=new int[heights.size()];
        int *rightSmaller=new int[heights.size()];
        stack<pair<int,int>>s;
        for(int i=0;i<heights.size();i++){
            while(!s.empty()&&heights[i]<=s.top().first){
                s.pop();
            }
            leftSmaller[i]=s.size()==0?-1:s.top().second;
            s.push({heights[i],i});
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty()&&heights[i]<=s.top().first){
                s.pop();
            }
            rightSmaller[i]=s.size()==0?heights.size():s.top().second;
            s.push({heights[i],i});
        }
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int leftArea=heights[i]*(i-leftSmaller[i]);
            int rightArea=heights[i]*(rightSmaller[i]-i);
            int area=leftArea+rightArea-heights[i];
            cout<<area<<" ";
            maxArea=max(maxArea,area);
                                     
        }
        return maxArea;
    }
};
