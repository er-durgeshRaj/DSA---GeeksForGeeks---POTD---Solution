// QUESTION
// Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

// Example 1:

// Input:
// k = 12, n = 3
// arr[] = [[1, 2, 3], 
//        [4, 6, 5], 
//        [3, 2, 1]]
// Output: 
// 2
// Explanation: 
// There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
// Example 2:

// Input:
// k = 16, n = 3
// arr[] = [[1, 2, 3], 
//        [4, 6, 5], 
//        [9, 8, 7]]
// Output: 
// 0 
// Explanation: 
// There are no possible paths that lead to sum=16
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function numberOfPath() which takes n, k and 2D matrix arr[][] as input parameters and returns the number of possible paths.

// Expected Time Complexity: O(n*n*k)
// Expected Auxiliary Space: O(n*n*k)

// Constraints:

// 1 <= k < 100
// 1 <= n < 100
// 0 <= arrij <= 200
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        int dr[] = {1, 0};
        int dc[] = {0, 1};
                 // D, R
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= n)
                return 0;
                
            return 1;
        };
        
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (n, vector<long long> (k + 1, -1)));
        
        function<long long(int, int, int)> helper = [&](int r, int c, int sum) -> long long {
            if(r == n - 1 and c == n - 1){
                return dp[r][c][sum] = sum == arr[r][c];
            }
            
            if(dp[r][c][sum] != -1)
                return dp[r][c][sum];
            
            dp[r][c][sum] = 0;
                
            if(arr[r][c] <= sum){
                for(int dir = 0; dir < 2; dir++){
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];
                    
                    if(valid(nr, nc))
                        dp[r][c][sum] += helper(nr, nc, sum - arr[r][c]);
                }            
            }
            
            return dp[r][c][sum];
        };
        
        return helper(0, 0, k);
    }
};
