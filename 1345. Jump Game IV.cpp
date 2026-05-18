class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int i = q.front();
                q.pop();

                if(i == n - 1)
                    return steps;

                vector<int> neighbors = mp[arr[i]];

                neighbors.push_back(i - 1);

                neighbors.push_back(i + 1);

                for(int next : neighbors) {

                    if(next >= 0 && next < n && !visited[next]) {

                        visited[next] = true;
                        q.push(next);
                    }
                }

                mp[arr[i]].clear();
            }

            steps++;
        }

        return -1;
    }
};