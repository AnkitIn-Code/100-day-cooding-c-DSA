//Pascal's triangle
				1
			1		1
		1		2		1	
	1		3		3		1
1		4		6		4		1
  
//Brute force
To count any element of any row or want to print any whole row we use formula nCr here we use r-1Cc-1
for(row=1->n)
{
temp=[] --- empty list
for(col=1->row){
temp.add(ncr(row-1,col-1));
}ans.add(temp);
}
return ans;

//Optimal soluction
 vector<int> generateno(int row){
    vector<int> ansrow;
    int ans=1;
    ansrow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        ansrow.push_back(ans);
    }
    return ansrow;
}
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateno(i));
        }
        return ans;
    }
};