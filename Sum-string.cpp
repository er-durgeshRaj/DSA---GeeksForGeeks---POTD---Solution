/* QUESTION
Given a string of digits, the task is to check if it is a ‘sum-string’. A string S is called a sum-string when it is broken down into more than one substring and the rightmost substring can be written as a sum of two substrings before it and the same is recursively true for substrings before it.

Example 1:

Input:
S = "12243660"
Output:
1
Explanation:
"12243660" can be broken down as {"12", "24", "36", "60"}.
We can get 60 from 24 and 36 as 24 + 36 = 60. Similarly 36 can be written as 12 + 24.
Example 2:

Input:
1111112223
Output:
1
Explanation:
"1111112223" can be broken down as {"1", "111", "112", "223"}.
We can get 223 from 111 and 1112 as 111 + 112 = 223. Similarly 112 can be written as 1 + 111.
Your Task:

You don't need to read input or print anything. Your task is to complete the function isSumString() which takes the string S and returns 1 is S is a sum-string otherwise returns 0.

Expected Time Complexity: O(|S|3)
Expected Auxiliary Space: O(|S|)

Constraints:
1 <= |S| <= 500
String consists of characters from '0' to '9'. */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SOLUTION
class Solution{   
public:
    int isSumString(string S){
        int n = S.size();
        
        auto sum = [](string a, string b) -> string {
            string ans = "";
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            
            int carry = 0;
            int index = 0;
            
            while(index < a.size() and index < b.size()){
                int sum = (a[index] - '0') + (b[index] - '0') + carry;
                carry = sum / 10;
                sum = sum % 10;
                
                ans += to_string(sum);
                ++index;
            }
            
            while(index < a.size()){
                int sum = (a[index] - '0') + carry;
                carry = sum / 10;
                sum = sum % 10;
                
                ans += to_string(sum);
                ++index;
            }
            
            while(index < b.size()){
                int sum = (b[index] - '0') + carry;
                carry = sum / 10;
                sum = sum % 10;
                
                ans += to_string(sum);
                ++index;
            }
            
            if(carry){
                ans += to_string(carry);
            }
            
            reverse(ans.begin(), ans.end());
            
            return ans;
        };
        
        function<bool(string &, string&, int, bool)> helper = [&](string &a, string &b, int p, bool valid) -> bool {
            if(p == n)
                return valid;
                
            string need = sum(a, b);
            
            string cur = "";
            
            for(int i = p; i < n; i++){
                cur += S[i];
                
                if(cur == need)
                    return helper(b, cur, i + 1, 1);
            }
            
            return 0;
        };
        
        for(int i = 1; i < n + 1; i++){ // length of the first string
            for(int j = i + 1; j < n + 1; j++){ // second string will end at j - 1
                string a = S.substr(0, i);
                string b = S.substr(i, j - i);
                
                if(helper(a, b, j, 0))
                    return 1;
            }
        }
        
        return 0;
    }
};
