/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
	map<int,UndirectedGraphNode*> graph;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(nullptr == node) return nullptr;
        if(graph.count(node->label)) return graph[node->label];
        UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
        graph.insert(pair<int, UndirectedGraphNode*>(node->label, clone));
        for(int i = 0; i < (int)(node->neighbors.size()); ++i) {
        	clone->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return clone;
    }
};