int countwalks(int graph[][V], int u, int v, int k) 
{ 
    // Table to be filled up using DP. The value count[i][j][e] will 
    // store count of possible walks from i to j with exactly k edges 
    int count[V][V][k+1]; 
  
    // Loop for number of edges from 0 to k 
    for (int e = 0; e <= k; e++) 
    { 
        for (int i = 0; i < V; i++)  // for source 
        { 
            for (int j = 0; j < V; j++) // for destination 
            { 
                // initialize value 
                count[i][j][e] = 0; 
  
                // from base cases 
                if (e == 0 && i == j) 
                    count[i][j][e] = 1; 
                if (e == 1 && graph[i][j]) 
                    count[i][j][e] = 1; 
  
                // go to adjacent only when number of edges is more than 1 
                if (e > 1) 
                { 
                    for (int a = 0; a < V; a++) // adjacent of source i 
                        if (graph[i][a]) 
                            count[i][j][e] += count[a][j][e-1]; 
                } 
           } 
        } 
    } 
    return count[u][v][k]; 
} 