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

/* O(1) Approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool column=true;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                column=false;
            }
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(j==0){
                    if(!column){
                        matrix[i][j]=0;
                    }
                }
                else{
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        
    }
};
*/
