//Rotate Matrix by 90deg
//Brute force
	make another ans matrix and place each element in its correct place 
	class Solution {
	public:
    	void rotate(vector<vector<int>>& matrix) {
        	int n= matrix.size();
        	int m=matrix[0].size();
        	vector<vector<int>> ans(m,n);
        	for(int i=0;i<n;i++){
            	for(int j=0;j<m;j++){
                	ans[j][n-1-i]=matrix[i][j];
            	}
        	}
    	}
	};
here space is o(n2) we optimise this
//Optimal
Transpose the matrix:- Means row became column and column became row 
and then reverse each row
-things to keep in mind when transposing matrix the diagonal will remain same all the time and the other places swap their place that why loop is running less
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};