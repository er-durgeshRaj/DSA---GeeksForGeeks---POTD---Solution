/*QUESTION
Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

Example 1:

Input: 
        4        
       /  \       
      2   5      
     / \   /  \     
    7  1 2  3    
      /
     6
Output: 
13
Explanation:
        4        
       /  \       
      2   5      
     / \   /  \     
    7  1 2  3 
      /
     6
The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
Example 2:

Input: 
          1
        /   \
       2    3
      / \    /  \
     4   5 6   7
Output: 
11
Explanation:
Use path 1->3->7, with sum 11.
Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
0 <= data of each node <= 104
SOLUTION*/
class Solution
{
public:
    int ans=0, mh=0;
    void solve(Node* root, int h, int s){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            s+=root->data;
            if(h>mh){
                ans=s;
                mh=h;
            }
            else if(h==mh){
                ans=max(ans, s);
            }
            return ;
        }
        
        s+=root->data;
        solve(root->left, h+1, s);
        solve(root->right, h+1, s);
        
        return;
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        solve(root, 0, 0);
        return ans;
    }
};
