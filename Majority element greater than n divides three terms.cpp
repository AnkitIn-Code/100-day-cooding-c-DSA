// Majority element greater than n/3 times
//Brute force
Traverse through whole array and then take each different element and then count its repetation if count>3 then add to the list and when the size reaches 2 of the list sop traversal
At max the ans list will hav 2 digits only
	eg.n=8  n/3=2     so count>2
		for an element in an array it can be 3+3=6 as count  
list=[]
for(int i=0;i<n-1;i++){
	if(list.size()==0 || list[0]!=nums[i]){
		count=0;
		for(j=0 ->n-1){
			if(nums[j]==nums[i]){
				count++;
			if(count>n/3){
				list.add(nums[i]);
			}
		}
	}
}
T.C=O(n2)

//Better solution
pseudocode

list=[]
mpp
for(i=0 ->n-1){
	map[arr[i]]++;
	if(mpp[arr[i]]==mm)
		list.add(arr[i]);
	if(list.size()==2) break;
}
sort(list.begin(),list.end());
T.C=O(N)
S.C=O(N); we need to optimise this 

//Optimal solution 
Same as n/2 one question
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int elem1=INT_MIN,elem2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count1==0 && elem2!=nums[i]){
                count1=1;
                elem1=nums[i];
            }
            else if(count2==0 && elem1 != nums[i]){
                count2=1;
                elem2=nums[i];
            }
            else if(elem1==nums[i]){
                count1++;
            }
            else if(elem2==nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> list;
        count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(elem1==nums[i]) count1++;
            if(elem2==nums[i]) count2++;
        }
        int min=n/3;
        if(count1>min) list.push_back(elem1);
        if(count2>min) list.push_back(elem2);
        sort(list.begin(),list.end());
        return list;
    }
};