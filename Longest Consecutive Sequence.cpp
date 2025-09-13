//Longest Consecutive Sequence
//Brute Force
Take a element from using loop inside which I do linear search  if I got the element the go for x+1 nad store the count in count var
then move that value to longest var
then again check and found count and check if count<longest the swap them
//Better 
Sort the array
take three variable 
count,last smaller,longest
1.frist take a element and check is it large than the left smaller and then put count to=1, longest=1,and last smaller to be that value
the move ahead if the next no is same as the pervious move to next element if new no is larger than the prvious then do the same if the contunity breaks then put count =0 and start again 
each time check if count is <largest if not swap
T.C=nlogn->sorting+n or checking

//Optimal
put everything in set data structure;
we put it in set data structure bec it contain only unique elements
we put items into set then take frist element check if that no-1 is in the set if yes the leave it ,if not then check if no+1 is there or not and take count of length

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=1;
        if(n==0) return 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    count=count+1;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};