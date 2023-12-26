// QUESTION
// Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.

// If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.

// Example 1:

// Input: N = 3, M = 3
// mat[][] =  1, 2, 3
//           -3,-2,-1
//            1, 7, 5

// Output:  1, 2, 3
//         -3,-2,-1

// Explanation: This is the largest sub-matrix,
// whose sum is 0.
// Example 2:

// Input: N = 4, M = 4
// mat[][] = 9, 7, 16, 5
//           1,-6,-7, 3
//           1, 8, 7, 9
//           7, -2, 0, 10

//  Output: -6,-7
//           8, 7
//          -2, 0 
// Your Task:
// You don't need to read input or print anything. You just have to complete the function sumZeroMatrix() which takes a 2D matrix mat[][], its dimensions N and M as inputs and returns a largest sub-matrix, whose sum is 0.

// Expected Time Complexity: O(N*M*M).
// Expected Auxiliary Space: O(N*M).


// Constraints:
// 1 <= N, M <= 100
// -1000 <= mat[][] <= 1000
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      int n=a.size();
      int m=a[0].size();
      vector<vector<int>> sum(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              sum[i][j]=a[i][j]+ (j>0?sum[i][j-1]:0);
          }
      }
      
      int maxarea=0,startrow=0,endrow=-1,startcol=0,endcol=-1;
      for(int c1=0;c1<m;c1++){
          for(int c2=c1;c2<m;c2++){
              vector<int> temp(n);
              for(int i=0;i<n;i++){
                  temp[i]=sum[i][c2]- (c1>0? sum[i][c1-1]:0);
              }
              unordered_map<int,int> mp;
              mp[0]=-1;
              int currsum=0;
              for(int i=0;i<n;i++){
                  currsum+=temp[i];
                  if(mp.find(currsum)!=mp.end()){
                      int area= (c2-c1+1)*(i-(mp[currsum]));
                      if(area>maxarea){
                          maxarea=area;
                          startrow=mp[currsum]+1;
                          endrow=i;
                          startcol=c1;
                          endcol=c2;
                      }
                  }
                  else{
                      mp[currsum]=i;
                  }
              }
          }
      }
      
      vector<vector<int>> ans;
      if(maxarea==0) return ans;
      for(int i=startrow;i<=endrow;i++){
          vector<int> t;
          for(int j=startcol;j<=endcol;j++){
              t.push_back(a[i][j]);
          }
          ans.push_back(t);
      }
      
      return ans;
  }
};
