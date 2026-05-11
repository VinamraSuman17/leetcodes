class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            string temp = to_string(nums[i]);
            for(int j=0; j<temp.size(); j++){
                int res = temp[j] - '0';  // stoi function only works with the string , not with the single character so that's why we are here using ascii valur technique for it 
                ans.push_back(res);
            }
        }
        return ans;
    }
};