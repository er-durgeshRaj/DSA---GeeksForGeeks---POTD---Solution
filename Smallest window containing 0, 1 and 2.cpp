// QUESTION
// Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

// Example 1:

// Input:
// S = 10212
// Output:
// 3
// Explanation:
// The substring 102 is the smallest substring
// that contains the characters 0, 1 and 2.
// Example 2:

// Input: 
// S = 12121
// Output:
// -1
// Explanation: 
// As the character 0 is not present in the
// string S, therefor no substring containing
// all the three characters 0, 1 and 2
// exists. Hence, the answer is -1 in this case.
// Your Task:
// Complete the function smallestSubstring() which takes the string S as input, and returns the length of the smallest substring of string S that contains all the three characters 0, 1 and 2.

// Expected Time Complexity: O( length( S ) )
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ length( S ) ≤ 105
// All the characters of String S lies in the set {'0', '1', '2'}
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    int smallestSubstring(string S) {
        int zero = -1, one = -1, two = -1, res = 100001;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '0') zero = i;
            if (S[i] == '1') one = i;
            if (S[i] == '2') two = i;

            if (zero == -1 || one == -1 || two == -1) continue;
            int minimum = min({one, zero, two});
            int maximum = max({one, zero, two});
            res = min(res, maximum - minimum + 1);
        }

        return res == 100001 ? -1 : res;
    }
};
