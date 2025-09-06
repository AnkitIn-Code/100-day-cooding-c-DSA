// removing duplicates form a sorted array
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for (int i = 1; i < n; i++) {
                       if(nums[i]!=nums[j]{
				j++;
				nums[j]=nums[i];
			}
        }

        return j+1;
    }
};