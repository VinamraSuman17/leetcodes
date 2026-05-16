class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int resultIdx = 0;
        while (l <= r) {
            /* ye hum usi liye kar rahe hi kyuki hume array main se duplicate ko count nahi karna hai toh binary search main agr duplicate hote hai toh hum unhe ignore kar dete hai or uske pointer ko shift kar dete hai */
            while(l<r && nums[l] == nums[l+1]) l++;
            while(l<r && nums[r] == nums[r-1]) r--;

            int mid = l + (r - l) / 2;

            if(nums[mid] < nums[resultIdx])
                resultIdx = mid;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid-1;
            }
        }

        return nums[resultIdx];
    }
};