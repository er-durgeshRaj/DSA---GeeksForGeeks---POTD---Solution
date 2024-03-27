/*QUESTION
Given a matrix mat[][] with r rows and c columns, where some cells are landmines (marked as 0) and others are safe to traverse. Your task is to find the shortest safe route from any cell in the leftmost column to any cell in the rightmost column of the mat. You cannot move diagonally, and you must avoid both the landmines and their adjacent cells (up, down, left, right), as they are also unsafe.

Example 1:

Input:
mat = [1, 0, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 0, 1],
      [1, 1, 1, 1, 0]
Output: 
6
Explanation: 
We can see that length of shortest
safe route is 6
[1 0 1 1 1]
[1 1 1 1 1]
[1 1 1 1 1]
[1 1 1 0 1] 
[1 1 1 1 0]
Example 2:

Input:
mat = [1, 1, 1, 1, 1],
      [1, 1, 0, 1, 1],
      [1, 1, 1, 1, 1]
Output: 
-1
Explanation: There is no possible path from
first column to last column.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findShortestPath() which takes the matrix as an input parameter and returns an integer denoting the shortest safe path from any cell in the leftmost column to any cell in the rightmost column of mat. If there is no possible path, return -1. 

Expected Time Complexity: O(r * c)
Expected Auxiliary Space: O(r * c)

Constraints:
1 <= r, c <= 103
0 <= mat[][] <= 1
SOLUTION*/
class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    
     {
       // code here
       int r = mat.size(), c = mat[0].size();
       vector<vector<int>> arr(r,vector<int>(c,1));
       int direRow[]={-1,0,1,0};
       int direCol[]={0,1,0,-1};
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               if(mat[i][j]==0){
                   arr[i][j]=0;
                   for(int k=0;k<4;k++){
                       int nr = direRow[k]+i;
                       int nc = direCol[k]+j;
                       if(nr>=0 and nr<r and nc>=0 and nc<c){
                           arr[nr][nc]=0;
                       }
                   }
               }
           }
       }
       vector<vector<int>> vis(r,vector<int>(c,0));
       queue<pair<int,pair<int,int>>> q;
       for(int i=0;i<r;i++){
           if(arr[i][0])q.push({1,{i,0}});
       }
       while(q.size()){
           auto temp = q.front();
           q.pop();
           int i = temp.second.first;
           int j = temp.second.second;
           int dis = temp.first;
           if(j==c-1)return dis;
           vis[i][j]=1;
           for(int k=0;k<4;k++){
               int nr = direRow[k]+i;
               int nc = direCol[k]+j;
               if(nr>=0 and nr<r and nc>=0 and nc<c and vis[nr][nc]==0 and arr[nr][nc]==1){
                   q.push({dis+1,{nr,nc}});
               }
           }
       }
       return -1;
    }
};
