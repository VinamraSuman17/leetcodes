class Solution {
public:
    int n;

    bool solve(vector<int>& arr, int i, vector<bool>& visited) {

        
        if(i < 0 || i >= n || visited[i])
            return false;

        if(arr[i] == 0)
            return true;

        visited[i] = true;

        return solve(arr, i + arr[i], visited) ||
               solve(arr, i - arr[i], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();

        vector<bool> visited(n, false);

        return solve(arr, start, visited);
    }
};