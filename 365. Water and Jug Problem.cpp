class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y < target) return false;
        vector<int> directions = {x,-x,y,-y};

        set<int> visited;
        queue<int> q;
        visited.insert(0);
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int direction : directions){
                int total = curr + direction;
                if(total == target) return true;
                if(total < 0 || total > x+y) continue;
                if(visited.find(total) == visited.end()){
                    q.push(total);
                    visited.insert(total);
                }
            }
        }
        return false;
    }
};