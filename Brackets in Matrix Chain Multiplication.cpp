// QUESTION
// Given an array p[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
// As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

// NOTE:

// Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also Please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
// As there can be multiple possible answers, the console would print "True" for the correct string and "False" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.
// Example 1:

// Input: 
// n = 5
// p[] = {40, 20, 30, 10, 30}
// Output: 
// True
// Explaination: 
// Let's divide this into matrix(only 4 are possible) 
// [ [40, 20] -> A
// , [20, 30] -> B
// , [30, 10] ->C
// , [10, 30] -> D ]
// First we perform multiplication of B & C -> (BC)
// then we multiply A to (BC) -> (A(BC))
// then we multiply D to (A(BC)) -> ((A(BC))D)
// so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.
// Example 2:

// Input: 
// n = 3
// p = {3, 3, 3}
// Output: 
// True
// Explaination: 
// The solution returned the string (AB), which performs minimum multiplications. The total number of multiplications are (3*3*3) = 27.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function matrixChainOrder() which takes n and p[] as input parameters and returns the string of parenthesis for n-1 matrices. Use uppercase alphabets to denote each matrix.

// Expected Time Complexity: O(n3)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 2 ≤ n ≤ 26 
// 1 ≤ p[i] ≤ 500
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution{
public:
    string matrixChainOrder(int p[], int n){
        vector<vector<pair<long long,int>>> dp(n, vector<pair<long long, int>> (n, {1e18, -1}));
        
        for(int i = 0; i < n - 1; i++){
            dp[i][i] = dp[i][i + 1] = {0, -1};
        }
        
        dp[n - 1][n - 1] = {0, -1};
        
        for(int i = n - 1; i > -1; i--){
            for(int j = i + 2; j < n; j++){
                for(int k = i + 1; k < j; k++){
                    long long cur = (long long)p[i] * (long long)p[j] * (long long)p[k] + dp[i][k].first + dp[k][j].first;
                    
                    if(cur < dp[i][j].first){
                        dp[i][j].first = cur;
                        dp[i][j].second = k;
                    }
                }
            }
        }
        
        vector<string> res(n + n - 1, "");
        char in;
        
        for(int i = 1, in = 'A'; i < n + n - 1; i += 2, in++)
            res[i] += in;
        
        function<void(int, int)> helper = [&](int i, int j) {
            if(j - i < 2)
                return;
            
            int start_pos = i * 2;
            int end_pos = j * 2;
            
            res[start_pos] += '(';
            res[end_pos] += ')';
            
            helper(i, dp[i][j].second);
            helper(dp[i][j].second, j);
        };
        
        helper(0, n - 1);
        
        string ans = "";
        
        for(auto i : res)
            ans += i;
        
        return ans;
    }
};
