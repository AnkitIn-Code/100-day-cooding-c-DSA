//Majority element that comes more than n/2 times in an array
//Brute force
 take a variable and then traverse whole array and count its freq then check if it is grater than n/2 if yes then return otherwise continue
T.C=O(n2)

//Better
Hashing which have element as key and count as value in a single table
 pseudocode:
map<int,int>mpp; --we can take any name here we tak mpp
for(int i=0;i<nums.size();i++){
	map[v[i]]++;
}
for(auto it: mpp){                                --------- way to iterate an map
	if(it.second>(v.size()/2)){
		return it.frist;
	}
}
return -1;
}
T.C=O(nlogn + n)  --here it is taking nlogn bec nis to traver element and logn bec we use odered map which sort in logn
S.C=O(N)
//Optimal
Moore's Voting algorithm
Step1: Moore's voting
if(count=0){
elem=a[i];
count=1;
}
else if(a[i]==elem){
count++;
}
else{
count--;
}
Step 2: Check weather the selected no is greater than n/2 or no
//CODE
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                elem=nums[i];
                count=1;
            }
            else if(nums[i]==elem){
                count++;
            }
            else{
                count--;
            }
        }
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==elem){
                count1++;
            }
        }
        if(count1>nums.size()/2){
            return elem;
        }
        return -1;
    }
};
 
 