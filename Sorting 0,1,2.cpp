//Sorting array with 0,1,2 
//Brute force approach
	Apply any sorting eg. merge sort
					T.C=nlogn ,S.C=N
//Better
	Take three variables count1,count2,count3 and store the occurance of each element
	then start loop from 0->count1:- put 0 in array then count1->count1+count2:-put 1 in array then count1+count2->n:-put 2
//Optimal 
	Dutch National Flag Algrithm
	0  ->  low-1=0
	low -> mid-1=1
	mid ->high=unsorted
	high  ->  n-1 =2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};