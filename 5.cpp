//union of two sorted array
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        vector<int> unionArray;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                if(unionArray.size()==0 || unionArray.back() != nums1[i]){
                    unionArray.push_back(nums1[i]);
                }
                i++;
            }
            else{
                if(unionArray.size()==0 || unionArray.back() != nums2[j]){
                    unionArray.push_back(nums2[j]);
                }
                j++;
            }
        }
        while(i<m){
            if(unionArray.size()==0 || unionArray.back() != nums1[i]){
                    unionArray.push_back(nums1[i]);
                }
                i++;
        }
        while(j<n){
            if(unionArray.size()==0 || unionArray.back() != nums2[j]){
                    unionArray.push_back(nums2[j]);
                }
                j++;
        }
        return unionArray;
    }
};