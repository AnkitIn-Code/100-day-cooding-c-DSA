//Count subarray having xor as K
//Brute force
Generate all subarrays using two loops 
class Solution {
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int xorSum = 0;
            for (int j = i; j < n; j++) {
                xorSum ^= nums[j];
                if (xorSum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
T.C=O(n2)
S.C=O(1)
//Optimal Solution
Here we are storing the values inside the map each time we check if the x is inside map or not if it is inside and store the no inside it
-       k
x   ---------
5,4,2,2,6,4 
--------------         x=xr^k
   (xr)

class Solution {
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        int xr=0;
        map<int,int> mpp;
        mpp[xr]++;
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
            int x=xr^k;
            count+=mpp[x];
            mpp[xr]++;
        }
        return count;
    }
};
