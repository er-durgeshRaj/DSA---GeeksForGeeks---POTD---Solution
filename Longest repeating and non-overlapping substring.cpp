// QUESTION
// Given a string s of length n, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. Return the longest non-overlapping substring. Return "-1" if no such string exists.

// Note: Multiple Answers are possible but you have to return the substring whose first occurrence is earlier.

// For Example: "abhihiab", here both "ab" and "hi" are possible answers. But you will have to return "ab" because it's first occurrence appears before the first occurrence of "hi".

// Example 1:

// Input:
// n = 9
// s = "acdcdacdc"
// Output:
// "acdc"
// Explanation:
// The string "acdc" is the longest Substring of s which is repeating but not overlapping.
// Example 2:

// Input:
// n = 7
// s = "heheheh"
// Output:
// "heh"
// Explanation:
// The string "heh" is the longest Substring of s which is repeating but not overlapping.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestSubstring() which takes an Integer n and a string s as input and returns the answer.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 <= n <= 103
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int res_length=0;
        int i, index=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(j-i > dp[i-1][j-1] && s[i-1]==s[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>res_length){
                        res_length=dp[i][j];
                        index=max(i,index);
                    }
                }
                else{
                    dp[i][j]=0;
                }
                
            }
        }
        string res="";
        if(res_length>0){
            for(i= index-res_length+1;i<=index;i++){
                res+=s[i-1];
            }
        }
        if(res==""){
            res="-1";
        }
        return res;
    }
};
