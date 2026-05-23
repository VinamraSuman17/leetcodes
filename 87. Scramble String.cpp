class Solution {
public:
    
    unordered_map<string, bool> dp;
    
    bool solve(string a, string b) {
        
        // already computed
        string key = a + " " + b;
        
        if(dp.count(key))
            return dp[key];
        
        // same strings
        if(a == b)
            return dp[key] = true;
        
        // lengths different
        if(a.size() != b.size())
            return dp[key] = false;
        
        // pruning:
        // if characters frequency different -> impossible
        string x = a;
        string y = b;
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        if(x != y)
            return dp[key] = false;
        
        int n = a.size();
        
        // try every split
        for(int k = 1; k < n; k++) {
            
            // CASE 1: no swap
            bool noSwap =
                solve(a.substr(0, k), b.substr(0, k)) &&
                solve(a.substr(k), b.substr(k));
            
            
            // CASE 2: swap
            bool swapCase =
                solve(a.substr(0, k), b.substr(n - k)) &&
                solve(a.substr(k), b.substr(0, n - k));
            
            
            if(noSwap || swapCase)
                return dp[key] = true;
        }
        
        return dp[key] = false;
    }
    
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};