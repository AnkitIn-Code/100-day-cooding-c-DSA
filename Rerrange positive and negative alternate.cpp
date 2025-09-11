//Rerrange positive and negative by sign
arr[]={3,1,-2,-5,2,-4}

//Brute force 
take two array pos and neg traverse loop and 
put positive in one and negative in another

then put positve element at even place and negative at odd start 0 index 
with positive

for(int i=0;i<n/2;i++){
	arr[2*i]=pos[i];
	arr[2*i+1]=neg[i];
}

T.C=O(N+n/2)
S.C=O(N)

//Optimal
T.C=O(N)
S.C=O(N)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,0);
        int posidx=0,negidx=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                arr[negidx]=nums[i];
                negidx+=2;
            }
            else{
                arr[posidx]=nums[i];
                posidx+=2;
            }
        }
        return arr;
    }
};


