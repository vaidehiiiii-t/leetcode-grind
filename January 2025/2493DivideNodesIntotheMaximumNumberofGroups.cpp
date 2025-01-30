class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, -1);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int maxGroups = 0;
        unordered_set<int> componentNodes;
        
        for (int i = 1; i <= n; i++) {
            if (visited[i] != -1) continue;
            
            componentNodes.clear();
            findConnectedComponent(i, graph, componentNodes);
            
            int maxDepth = -1;
            for (int node : componentNodes) {
                maxDepth = max(maxDepth, getMaxDepth(node, componentNodes, graph, visited));
            }
            
            if (maxDepth == -1) return -1;
            maxGroups += maxDepth;
        }
        
        return maxGroups;
    }

private:
    void findConnectedComponent(int node, vector<vector<int>>& graph, unordered_set<int>& componentNodes) {
        componentNodes.insert(node);
        for (int neighbor : graph[node]) {
            if (componentNodes.count(neighbor) == 0) {
                findConnectedComponent(neighbor, graph, componentNodes);
            }
        }
    }

    int getMaxDepth(int start, unordered_set<int>& componentNodes, vector<vector<int>>& graph, vector<int>& visited) {
        for (int node : componentNodes) visited[node] = -1;
        
        queue<int> q;
        int depth = 1;
        
        q.push(start);
        visited[start] = 1;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int neighbor : graph[cur]) {
                if (visited[neighbor] == -1) {
                    visited[neighbor] = visited[cur] + 1;
                    depth = max(depth, visited[neighbor]);
                    q.push(neighbor);
                } else if (abs(visited[cur] - visited[neighbor]) != 1) {
                    return -1;
                }
            }
        }
        
        return depth;
    }
};


//method 2 BFS+ distance
class Solution {
public:
    int magnificentSets(int numNodes, vector<vector<int>>& edgesList) {
        vector<vector<int>> adjacencyList(numNodes);
        for (auto& edge : edgesList) {
            int node1 = edge[0] - 1, node2 = edge[1] - 1;
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }
        vector<int> nodeDistances(numNodes);
        for (int startNode = 0; startNode < numNodes; ++startNode) {
            queue<int> nodeQueue{{startNode}};
            vector<int> distance(numNodes);
            distance[startNode] = 1;
            int maxDistance = 1;
            int rootNode = startNode;
            while (!nodeQueue.empty()) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();
                rootNode = min(rootNode, currentNode);
                for (int neighbor : adjacencyList[currentNode]) {
                    if (distance[neighbor] == 0) {
                        distance[neighbor] = distance[currentNode] + 1;
                        maxDistance = max(maxDistance, distance[neighbor]);
                        nodeQueue.push(neighbor);
                    } else if (abs(distance[neighbor] - distance[currentNode]) != 1) {
                        return -1;
                    }
                }
            }
            nodeDistances[rootNode] = max(nodeDistances[rootNode], maxDistance);
        }
        return accumulate(nodeDistances.begin(), nodeDistances.end(), 0);
    }
};