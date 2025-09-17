//Merge overlapping subarrays
	(1,3)(2,6)(8,9)(9,11)(8,10)(2,4)(15,18)(16,17)
	at last we will have = {1,6}{8,11}{15,18}

explanation:
	----------                      ------------
	 |   -----------                      -------------                       --------
	 |   |----------------           -----       |      |               ---------------------
	1  2     3    4    6          8    9    10    11           15     16    17    18


//Brute force
Frist of sort the given list and then check for the intervals
for intervals 1. like in this case we suppose that 1,3 is my interval  next is 2,4 we find it is overlapping as 2 < 3 same for 2,6
now our interval is expanded to 1,6 and now comes 8,9 we find 8>6 which is outside the interval so we leave this hence we got our first interval now move 
to the next intervals after 1,3 now if the next interval is already in our final interval 
we move to next until we find next interval,

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(!ans.empty() && end<= ans.back()[1]){
                    continue;
            }
            for(int j=i+1;j<n;j++){
                if(intervals[j][0]<= end){
                    end=max(end,intervals[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
T.C=O(n logn --sorting)+O(2n) --- each element Is traversed twise for checking the each intervals
S.C=O(n)
//Optimal solution
instead for checking frist with 1,3 then moving next we check each time to time

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
T.C=O(nlogn) +O(n)
S.C=O(n)