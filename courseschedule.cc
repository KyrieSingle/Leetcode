class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prer) {
        vector<vector<int>> gragh(numCourses);
        vector<int> visited(numCourses, 0); 
        for (int i = 0; i < prer.size(); i++) {
            gragh[prer[i].second].push_back(prer[i].first);
        }
        bool cycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (cycle) return false;
            if (visited[i] == 0) dFS(i, gragh, visited, cycle);
        }
        return true;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegree(graph);
        queue<int> zeros;
        for (int i = 0; i < numCourses; i++)
            if (!degrees[i]) zeros.push(i);
        vector<int> toposort;
        for (int i = 0; i < numCourses; i++) {
            if (zeros.empty()) return {};
            int zero = zeros.front();
            zeros.pop();
            toposort.push_back(zero);
            for (int neigh : graph[zero]) {
                if (!--degrees[neigh])
                    zeros.push(neigh);
            }
        }
        return toposort;
    }

private:
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph; 
    }

    void dFS(int node, vector<vector<int>> &gragh, vector<int> &visited, bool &cycle) {
        if (visited[node] == 1) {
            cycle = true; 
            return;
        }
        visited[node] = 1;
        for (int i = 0; i < gragh[node].size(); i++) {
            dFS(gragh[node][i], gragh, visited, cycle);
            if (cycle) return; 
        }
        visited[node] = 2; 
    }

    vector<int> computeIndegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};