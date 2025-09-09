//Longest Sub array With sum k
..Optimal approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i,j,len=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum=sum+nums[j];
                if(sum==k){
                    len=max(len,j-i+1);
                }
            }
        }
        return len;
    }
};