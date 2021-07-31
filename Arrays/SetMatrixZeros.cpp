class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int *row=new int[m]{0};
        int *column=new int[n]{0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    column[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(row[i]==1){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(column[j]==1){
                for(int i=0;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
