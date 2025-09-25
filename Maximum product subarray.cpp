//Maximum product subarray
//Brute force 
two pointer
//Optimal
come from both sides ans check product 
product which is maximum store it in max1 variable

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),max1=INT_MIN;
        int prefix=1,sufix=1;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(sufix==0) sufix=1;
            prefix=prefix*nums[i];
            sufix=sufix*nums[n-i-1];
            max1=max(max1,max(prefix,sufix));
        }
        return max1;
    }
};