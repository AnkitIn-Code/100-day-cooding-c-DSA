//Set Matrix Zero
Basically we need to mark the matrix with zero where we find any zero in traversal then set that row and that column wole to be zero
//Brute force
1.Traver to each element
2.if found zero put that whole column to -1 except to 0
3.same for row 
4.Traverse again that array and now the elements which are set to -1 are now setted to 0 
5.Now our array is ready
T.C=O(n3) approx. as traversal will take n*m time then we run two function mark 	I and mark j each run n,m times then at last n*m times to change to zero
	=(n*m)*(n+m)+(n*m) approx. n3
//Better Approach
	Here we will take two array for column and row different so now we will 	mark the column where we find atleast 1 zero ,same for row 
	At last put zero into marked row,column
//Consider as best but spae complexity lacks in this
 class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> col(m,0);
        vector<int> row(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
	T.C=O(N2) ye best h
	S.C=O(N)+O(M) we need to optimise this
//Optimal 
	Here we have not used any extra array to store check we have done it in array itself so 
	we frist mark whom to make 0 then frist make the inside 0 then loop over the outer one's

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col1=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col1=0;
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=1;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(col1==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};