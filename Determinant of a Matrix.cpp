// QUESTION
// Given a square matrix of size n*n. The task is to find the determinant of this matrix.

// Example 1:

// Input:
// n = 4
// matrix[][] = {{1, 0, 2, -1},
//               {3, 0, 0, 5},
//               {2, 1, 4, -3},
//               {1, 0, 5, 0}}
// Output: 30
// Explanation:
// Determinant of the given matrix is 30.
// Example 2:

// Input:
// n = 3
// matrix[][] = {{1, 2, 3},
//               {4, 5, 6},
//               {7, 10, 9}}
// Output: 12
// Explanation:
// Determinant of the given matrix is 12.
// Your Task:
// You don't need to read input or print anything. Complete the function determinantOfMatrix() that takes matrix and its size n as input parameters and returns the determinant of the matrix.

// Expected Time Complexity: O(N4)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 <= N <= 10
// -10 <= mat[i][j] <= 10
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution
{   
    public:
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        if(n==1) return matrix [0][0];
        if(n==2)return matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
        int ans=0;
        int sign=1;
        for(int i=0;i<n;i++){
            vector<vector<int>> temp(n - 1,vector<int>(n - 1));
            int row=0;
            for(int col=0;col<n;col++){
                if(col==i) continue;
                for(int k=1;k<n;k++)  temp[k-1][row]=matrix[k][col];
                    row++;
            }
            ans+=sign*matrix[0][i]*determinantOfMatrix(temp,n-1);
            sign=-sign;
        }
        return ans;
    }
};
