class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        int i = 0;
        int j = n - 1;

        while(i < j){

            int a = min(nums[i], nums[j]);
            int b = max(nums[i], nums[j]);

            // initially 2 moves for all
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 1 move range
            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;

            // 0 move at exact sum
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;

            i++;
            j--;
        }

        int ans = INT_MAX;
        int curr = 0;

        for(int s = 2; s <= 2 * limit; s++){

            curr += diff[s];

            ans = min(ans, curr);
        }

        return ans;
    }
};