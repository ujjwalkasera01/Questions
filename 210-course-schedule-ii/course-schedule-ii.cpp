class Solution {
private:
    bool kahnAlgo(vector<vector<int>> &adj, int n, vector<int> &indegree, vector<int> &ans)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto a : adj[curr])
            {
                indegree[a] -= 1;
                if (indegree[a] == 0)
                    q.push(a);
            }
            ans.push_back(curr);
            count++;
        }

        if (count != n)
            return false;
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses); 
        vector<int> indegree(numCourses, 0); 

        for (int i = 0; i < n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;
        }

        vector<int> ans;

        if (kahnAlgo(adj, numCourses, indegree, ans))
            return ans;

        return {};
    }
};