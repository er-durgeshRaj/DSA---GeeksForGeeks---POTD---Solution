// QUESTION
// Given a binary tree with N nodes, in which each node value represents number of candies present at that node. In one move, one may choose two adjacent nodes and move only one candy from one node to another (the move may be from parent to child, or from child to parent.) 
// The task is to find the number of moves required such that every node has exactly one candy.
// Note that the testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.

// Example 1:

// Input :      3
//            /   \
//           0     0 
// Output : 2
// Explanation: 
// From the root of the tree, we move one 
// candy to its left child, and one candy to
// its right child.
// Example 2:

// Input :      0
//            /   \
//           3     0  
// Output : 3
// Explanation : 
// From the left child of the root, we move 
// two candies to the root [taking two moves]. 
// Then, we move one candy from the root of the 
// tree to the right child.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function distributeCandy() which takes the root of the tree as input and returns the number of moves required such that every node has exactly one candy.
 
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(height of the tree)
 
// Constraints:
// 1 <= N <= 104
// 0 <= Value of each node <= 104
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution
{
    public:
    int distributeCandy(Node* root)
    {
        map<Node *, int> subtree, candies;
        int ans = 0;
        
        function<void(Node *)> dfs1 = [&](Node * node) {
            if(!node)
                return;
                
            subtree[node] = 1;
            candies[node] = node -> key;
            
            dfs1(node -> left);
            dfs1(node -> right);
            
            subtree[node] += subtree[node -> left] + subtree[node -> right];
            candies[node] += candies[node -> left] + candies[node -> right];
        };
        
        dfs1(root);
        
        function<void(Node *)> dfs2 = [&](Node * node) {
            if(!node)
                return;
            
            int leftextra = candies[node -> left] - subtree[node -> left];
            // if this value is negative it is deficient
            // if this value is positive it has more candies
            
            int rightextra = candies[node -> right] - subtree[node -> right];
            
            ans += abs(leftextra) + abs(rightextra);
            
            dfs2(node -> left);
            dfs2(node -> right);
        };
        
        dfs2(root);
        
        return ans;
    }
};
