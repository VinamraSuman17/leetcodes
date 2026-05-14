class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> permArray(n,n-1);
        for(int i=0; i<n-1; i++){
            permArray[i] = i+1;
        }
       

        sort(begin(nums), end(nums));

        return nums == permArray;
    }
};