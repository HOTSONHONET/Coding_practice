// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.


bool isSafe(int v, bool graph[101][101], int V,
            int color[], int c)
{
    for(int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
             
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m,
                       int V, int color[], int v)
{
     
    /* base case: If all vertices are
       assigned a color then return true */
    if (v == V)
        return true;
 
    /* Consider this vertex v and
       try different colors */
    for(int c = 1; c <= m; c++)
    {
         
        /* Check if assignment of color
           c to v is fine*/
        if (isSafe(v, graph, V, color, c))
        {
            color[v] = c;
 
            /* recur to assign colors to
               rest of the vertices */
            if (graphColoringUtil(
                graph, m, V, color, v + 1) == true)
                return true;
 
            /* If assigning color c doesn't
               lead to a solution then remove it */
            color[v] = 0;
        }
    }
 
    /* If no color can be assigned to
       this vertex then return false */
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    // Initialize all color values as 0.
    // This initialization is needed
    // correct functioning of isSafe()
    int color[V];
    for(int i = 0; i < V; i++)
        color[i] = 0;
 
    // Call graphColoringUtil() for vertex 0
    if (graphColoringUtil(graph, m, V, color, 0) == false)
        return false;

    return true;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends