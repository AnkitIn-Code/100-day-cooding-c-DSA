//Maximum subarray sum 
//Brute force 
use two pointer i and j and then start ifro 0 then nested loop of j from j=i then 
take sum of all subarray and put the max sum in sum variable then last return max variable

//Optimal
Kadane's Algorithm
basically in this we put max var with min value then traverse array and then adding in the sum each time sum <0 overwrite sum=0
then store the max in sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0,max=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }

        }
        return max;
    }
};