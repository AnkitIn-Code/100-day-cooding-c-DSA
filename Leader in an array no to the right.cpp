//Leader in an array no to the right are small
Optimal
traverse from last then take each element 
take an var maximun and an array to return now compare if last is>maximum
then max=that index and push that in array
move ahead and then check if any no greater than the maximum them put it max and store that element in array
//code
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int maxi = INT_MIN;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] >= maxi) {
                ans.push_back(nums[i]);
                maxi = nums[i];
            }
        }

        // Reverse to maintain left-to-right order of leaders
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
