// QUESTION
// Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

// Example 1:

// Input:
//         1
//       /   \
//      2    3
//     / \    /   \
//    4   5 6   7
// Output:
// 1 3 2 4 5 6 7
// Example 2:

// Input:
//            7
//         /     \
//        9      7
//      /  \      /   
//     8   8  6     
//    /  \
//   10  9 
// Output:
// 7 7 9 8 8 6 9 10 
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n <= 105
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution{

    public:

    //Function to store the zig zag order traversal of tree in a list.

    vector <int> zigZagTraversal(Node* root)

    {

    	// Code here

    	vector<vector<int>>traversal;

    	queue<Node*>q;

    	q.push(root);

    	

    	while(!q.empty()){

    	    int n=q.size();

    	    vector<int>level;

    	    for(int i=0;i<n;i++){

    	        Node* node=q.front();

    	        q.pop();

    	        

    	        level.push_back(node->data);

    	        if(node->left){

    	            q.push(node->left);

    	        }

    	        if(node->right){

    	            q.push(node->right);

    	        }

    	    }

    	    traversal.push_back(level);

    	}

    	vector<int>ans;

    	for(int i=0;i<traversal.size();i++){

    	    if(i%2==1){

    	        reverse(traversal[i].begin(), traversal[i].end());

    	    }

    	    for(auto it:traversal[i]){

    	        ans.push_back(it);

    	    }

    	}

    	return ans;
    }

};
