/*QUESTION
Vertex cover of an undirected graph is a list of vertices such that every vertex not in the vertex cover shares their every edge with the vertices in the vertex cover. In other words, for every edge in the graph, atleast one of the endpoints of the graph should belong to the vertex cover. You will be given an undirected graph G, and your task is to determine the smallest possible size of a vertex cover.

Example 1:

Input:
N=5
M=6
edges[][]={{1,2}
           {4, 1},
           {2, 4},
           {3, 4},
           {5, 2},
           {1, 3}}
Output:
3
Explanation:
{2, 3, 4} forms a vertex cover
with the smallest size.
Example 2:

Input:
N=2
M=1
edges[][]={{1,2}} 
Output: 
1 
Explanation: 
Include either node 1 or node 2
in the vertex cover.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function vertexCover() which takes the edge list and an integer n for the number of nodes of the graph as input parameters and returns the size of the smallest possible vertex cover.

Expected Time Complexity: O(M*2N)
Expected Auxiliary Space: O(N2)

 Constraints:
1 <= N <= 16
1 <= M <= N*(N-1)/2
1 <= edges[i][0], edges[i][1] <= N
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  SOLUTION*/
class Solution{
    public:
     int vertexCover(int num_nodes, vector<pair<int, int>> &edges) {
         if (num_nodes == 0) {
            return 0;
        }
        // Initialize separate vectors for edges connected to two different vertices.
        vector<pair<int, int>> first_vertex_edges, second_vertex_edges;

        // Get the first edge to compare with other edges.
        int first_vertex = edges[0].first;
        int second_vertex = edges[0].second;
        int count_first_vertex = 0, count_second_vertex = 0;

        // Iterate through the edges to categorize them based on their vertices.
        for ( auto edge : edges) {
            int vertex1 = edge.first;
            int vertex2 = edge.second;

            // Check if the current edge is not connected to the first vertex.
            if (!(vertex1 == first_vertex || vertex2 == first_vertex)) {
                first_vertex_edges.push_back({vertex1, vertex2});
                count_first_vertex++;
            }

            // Check if the current edge is not connected to the second vertex.
            if (!(vertex1 == second_vertex || vertex2 == second_vertex)) {
                second_vertex_edges.push_back({vertex1, vertex2});
                count_second_vertex++;
            }
        }

        // Recursively find the minimum vertex cover size for both sets of edges.
        return 1 + min(
            vertexCover(count_first_vertex, first_vertex_edges),
            vertexCover(count_second_vertex, second_vertex_edges)
        );
     }
};
