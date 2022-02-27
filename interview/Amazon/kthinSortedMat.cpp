typedef pair<int, pair<int, int>> node;
#define f first
#define s second

int kthSmallest(int mat[MAX][MAX], int n, int k){
    priority_queue<node, vector<node>, greater<node>> q;
    for(int i=0;i<n;i++) q.push({mat[0][i], {0, i}});
    int c=1;
    while(c<k){
        node tp = q.top();
        q.pop();
        c++;
        int i=tp.s.f, j=tp.s.s;
        if(i<n-1)
            q.push({mat[i+1][j], {i+1, j}});
    }
    node tp = q.top();
    return tp.f;
}   