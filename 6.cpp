//Finding missing no from an array
brute force- is to do linear seach with nested loop;
optimal -Hasing
#include <bits/stdc++.h>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n=nums.size();
    vector<int> hash(n+1, 0);
    for(int i=0;i<n;i++){
        hash[nums[i]]=1;
    }
    int j;
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return 0;
    }
};
Better-using Sum
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int sum2=0;
        for(int i=0;i<n;i++){
            sum2=sum2+nums[i];
        }
        return sum-sum2;
    }
};