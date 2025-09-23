//Reverse pairs
we are give with an array in which there exists a pair if  a[i]>2* arr[i+1]or a[j]
//Brute force
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>2*nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
T.C=O(n2)

//Optimal solution
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int>&arr,int low,int mid,int high){
    int right=mid+1;
    int count=0;
    for(int i=low;i<=mid;i++){
while (right <= high && (long long)arr[i] > 2LL * arr[right]) right++;
        count=count+(right-(mid+1));
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int count=0;
    if (low >= high) return count;
    int mid = (low + high) / 2 ;
    count +=mergeSort(arr, low, mid);  // left half
    count+=mergeSort(arr, mid + 1, high); // right half
    count+=countPairs(arr,low,mid,high);
    merge(arr, low, mid, high);  // merging sorted halves
    return count;
}
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        return mergeSort(nums,low,high);
    }
};
here we are having some error due to the big size of data so we just convert it to long long