// QUESTION
// Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

// Example 1:

// Input:
// A = "geeks"
// B = "geeksfor", 
// C = "geeksforgeeks"
// Output: 5
// Explanation: 
// "geeks"is the longest common
// subsequence with length 5.
// Example 2:

// Input: 
// A = "abcd"
// B = "efgh"
// C = "ijkl"
// Output: 0
// Explanation: 
// There's no subsequence common
// in all the three strings.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.

// Expected Time Complexity: O(n1*n2*n3).
// Expected Auxiliary Space: O(n1*n2*n3).

// Constraints:
// 1 <= n1, n2, n3 <= 20
// Elements of the strings consitutes only of the lower case english alphabets.
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution
{
    public:
  int help(string A,string B,string C,int i,int j,int k,int n1,int n2,int n3,vector<vector<vector<int>>> &dp){
            if(i==n1 or j==n2 or k==n3)return 0;
            if(dp[i][j][k]!=-1)return dp[i][j][k];
            if(A[i]==B[j] and A[i]==C[k]){
                return dp[i][j][k] = 1+help(A,B,C,i+1,j+1,k+1,n1,n2,n3,dp);
            }
            int a = help(A,B,C,i+1,j,k,n1,n2,n3,dp);
            int b = help(A,B,C,i,j+1,k,n1,n2,n3,dp);
            int c = help(A,B,C,i,j,k+1,n1,n2,n3,dp);
            return dp[i][j][k] = max({a,b,c});
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            return help(A,B,C,0,0,0,n1,n2,n3,dp);
        }
    };
