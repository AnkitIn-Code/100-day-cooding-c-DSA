//Maximum subarray length with sum zero
//Brute force
We use two pointer approach in which we use two loops and traverse to each subarray possible check if sum is 0 and maintain the max length and at last return that length
T.C=O(n2)
//Optimal solution
In this soluction we are generally using an hash map to store the sum if its is not equal to 0 and is not present in the hash map
and to find max we are just checking length of each sum first if sum==0 then we get length by index and if find in hash we get to know that if the sum is already present in hash ,
we can say that from that onwards the next elements are having their sum 0
 class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        unordered_map<int,int> mpp;
        int sum=0,max1=0;
        for(int i=0;i<n;i++){
          sum +=arr[i];
          if(sum==0){
            max1=i+1;
          }
          else{
            if(mpp.find(sum)!=mpp.end()){
              max1=max(max1,i-mpp[sum]);
            }
            else{
              mpp[sum]=i;
            }
          }
        }
        return max1;
    }
};
T.C=O(n logn)      ------ here n is for sum and logn is for hashmap we use
S.C=O(n)