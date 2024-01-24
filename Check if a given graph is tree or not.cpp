// QUESTION
// You are given an undirected graph of N nodes (numbered from 0 to N-1) and M edges. Return 1 if the graph is a tree, else return 0.

// Note: The input graph can have self-loops and multiple edges.

// Example 1:

// Input:
// N = 4, M = 3
// G = [[0, 1], [1, 2], [1, 3]]
// Output: 
// 1
// Explanation: 
// Every node is reachable and the graph has no loops, so it is a tree
// Example 2:

// Input:
// N = 4, M = 3
// G = [[0, 1], [1, 2], [2, 0]]
// Output: 
// 0
// Explanation: 
// 3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number nodes in the input graph) and the edges representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 2*105
// 0 <= M <= 2*105
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &edge) {
        if(m != n - 1)
            return 0;
            
        vector<int> vis(n, 0);
        vector<vector<int>> g(n);
        
        for(int i = 0; i < m; i++){
            g[edge[i][0]].push_back(edge[i][1]);
            g[edge[i][1]].push_back(edge[i][0]);
        }
        
        function<bool(int, int)> dfs = [&](int node, int parent) -> bool {
            bool ans = 1;
            vis[node] = 1;
            
            for(auto child : g[node]){
                if(!vis[child])
                    ans = ans and dfs(child, node);
                else if(child != parent)
                    return 0;
            }
            
            return ans;
        };
        
        bool ans = 1;
        int cc = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans = ans and dfs(i, -1);
                ++cc;   
            }
        }
        
        return ans and cc == 1;
    }
};
