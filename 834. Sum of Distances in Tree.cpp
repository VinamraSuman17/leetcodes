class Solution {
public:

    vector<vector<int>> adj;
    vector<int> count;
    vector<int> ans;
    int n;

    void dfs1(int node, int parent, int depth){

        count[node] = 1;
        ans[0] += depth;

        for(int child : adj[node]){

            if(child == parent)
                continue;

            dfs1(child, node, depth + 1);

            count[node] += count[child];
        }
    }

    void dfs2(int node, int parent){

        for(int child : adj[node]){

            if(child == parent)
                continue;

            ans[child] =
                ans[node]
                + n
                - 2 * count[child];

            dfs2(child, node);
        }
    }

    vector<int> sumOfDistancesInTree(int N,
                                     vector<vector<int>>& edges) {

        n = N;

        adj.resize(n);
        count.resize(n);
        ans.resize(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1, 0);

        dfs2(0, -1);

        return ans;
    }
};