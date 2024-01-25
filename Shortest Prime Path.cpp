// QUESTION
// You are given two four digit prime numbers num1 and num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

// Example 1:

// Input:
// num1 = 1033 
// num2 = 8179
// Output: 6
// Explanation:
// 1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
// There are only 6 steps reuired to reach num2 from num1. 
// and all the intermediate numbers are 4 digit prime numbers.
// Example 2:

// Input:
// num1 = 1033 
// num2 = 1033
// Output:
// 0
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers num1 and num2 as input parameters and returns the distance of the shortest path from num1 to num2. If it is unreachable then return -1.

// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1000<=num1,num2<=9999
// num1 and num2 are prime numbers.
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution{   
public:
    int solve(int Num1,int Num2){
    vector<int> prime(10000,1);
      for(int i=2;i*i<10000;i++)
      {
          if(prime[i])
          {
              for(int j=2*i;j<10000;j+=i) prime[j]=0;
          }
      }
      unordered_set<int> st;
      for(int i=1000;i<10000;i++) if(prime[i]) st.insert(i);
      queue<pair<int,int>> q;
      q.push({0,Num1});
      while(!q.empty())
      {
          int dist = q.front().first;
          int n = q.front().second;
          q.pop();
          if(n == Num2) return dist;
          string num=to_string(n);
          for(int i=0;i<4;i++)
          {
              for(int j=0;j<=9;j++)
              {
                  char c=num[i];
                  num[i]=('0'+j);
                  int nNum=stoi(num);
                  if(st.find(nNum) != st.end())
                  {
                    st.erase(nNum);
                    if(Num2 == nNum) return dist+1;
                    q.push({dist+1,nNum});
                  }
                  num[i]=c;
              }
              
          }
      }
      return -1;
      
    }
};
