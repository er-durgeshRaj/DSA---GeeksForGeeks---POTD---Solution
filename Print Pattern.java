// QUESTION
// Print a sequence of numbers starting with N, without using loop, where replace N with N - 5, until N > 0. After that replace N with N + 5 until N regains its initial value.

// Example 1:

// Input: 
// N = 16
// Output: 
// 16 11 6 1 -4 1 6 11 16
// Explaination: 
// The value decreases until it is greater than 0. After that it increases and stops when it becomes 16 again.
// Example 2:

// Input: 
// N = 10
// Output: 
// 10 5 0 5 10
// Explaination: It follows the same logic as per the above example.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function pattern() which takes N as input parameters and returns a list containing the pattern.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// -105 ≤ N ≤ 105
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//SOLUTION
class Solution{
    public List<Integer> pattern(int N){
        // code here
        List<Integer> list = new ArrayList<>();
        list.add(N);
        if(N<=0) return list;
        
        solve(list,N-5,true,N);
        return list;
    }
    
    void solve(List<Integer> list, int n, boolean flag, int k){
        list.add(n);
        
        if(n>0 && flag) solve(list,n-5,true,k);
        if(n<=0) solve(list,n+5,false,k);
        if(n>0 && !flag && n<k) solve(list,n+5,false,k);
        else return ;
    }
}
