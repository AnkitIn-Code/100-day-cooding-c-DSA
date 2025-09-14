//Number of sub arrays ith sum k
//Brute Force
take two pointer i ,j take sum til numsogj if sum==k tehn count++ ans at laast print count;
//Optimal
we use map
so here we stoew the presume into map and then check if x-k exists in map or not if ys count ++ if no add to map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int,int> mpp;
        mpp[0]=1;
        int n=nums.size();
        int presum=0,count=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int rem=presum-k;
            count+=mpp[remove];
            map[presum]+=1;
        }
        return count
    }
};
