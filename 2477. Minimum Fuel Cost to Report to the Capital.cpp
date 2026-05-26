class Solution {
public:

    long long fuel = 0;

    int dfs(int node, int parent,
            vector<vector<int>>& adj,
            int seats) {

        // khud ka representative
        int people = 1;

        // children traverse karo
        for (auto neigh : adj[node]) {

            if (neigh == parent)
                continue;

            people += dfs(neigh, node, adj, seats);
        }

        // capital ke liye fuel add nahi hoga
        if (node != 0) {

            // ceil(people / seats)
            fuel += (people + seats - 1) / seats;
        }

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        int n = roads.size() + 1;

        vector<vector<int>> adj(n);

        // graph build
        for (auto &it : roads) {

            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, adj, seats);

        return fuel;
    }
};