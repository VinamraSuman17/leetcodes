class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[A[i]]++;
            mp[B[i]]++;

            int count = 0;

            // traverse map to count elements with freq >= 2
            for(auto &it : mp) {
                if(it.second >= 2) {
                    count++;
                }
            }

            result.push_back(count);
        }

        return result;
    }
};