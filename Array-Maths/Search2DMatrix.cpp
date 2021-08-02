//O(m+n);
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target)
                return true;
            if(target<matrix[i][j])
                j--;
            else
                i++;
        }
        return false;
    }
};

/* Binary Search Solution If Complete Marix is Sorted O(log(m*n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int column=matrix[0].size();
        int high=(row*column-1);
        int low=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid/column][mid%column]==target){
                return true;
            }
            if(matrix[mid/column][mid%column]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return false;
        
        
    }
};

/*
