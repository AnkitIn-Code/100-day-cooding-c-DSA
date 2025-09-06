//Rotate array by kth index
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k=k%n;
    vector<int> temp(k);
    int a=0;
    for (int i = n - k; i < n; i++) {
            temp[a] = nums[i];
            a++;
        }
    for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
    int j=0;
    for(int i=0;i<k;i++){
        nums[i]=temp[j];
        j++;
    }}
};