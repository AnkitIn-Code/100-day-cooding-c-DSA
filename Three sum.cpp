//Three sum
Here we are making a triplet sum which is equal to 0
//Brute force
so we run three loop i to n,j=i+1 to n,an k=j+1to nafter which we may have duplicate values also so we just sort the order of them and store them in set as set store only unique elements
``Code``
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
T.C=O(n3)+log(no of unique triplet)
S.C=O(2*no of triplets)
//Better
for better we use hash map 
loop me traverse kr usme i and j ki loop chale gi abb i and j aa jaye ge k=-(i+j)
and check if k is in hash or not if yes then that is our triplet if not move j and check again
``code``
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            set<int> dup;
            for(int j=i+1;j<n;j++){
                int k=-(nums[i]+nums[j]);
                if(dup.find(k) != dup.end()){
                    vector<int> temp={nums[i],nums[j],k};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                dup.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
T.C=O(n2*logm) m is variable
S.C=O(n)+O(no of triplets)
//Optimal Soluction
``Code
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]== nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};