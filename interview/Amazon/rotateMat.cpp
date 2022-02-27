void rotateMatrix(int mat[][N]) {
	for(int x=0;x<N/2;x++){
    	for(int y=x;y<N-x-1;y++){ // remember
        	int tmp = mat[x][y];
          	mat[x][y] = mat[y][N-x-1];
          	mat[y][N-x-1] = mat[N-x-1][N-y-1];
          	mat[N-x-1][N-y-1] = mat[N-y-1][x];
          	mat[N-y-1][x] = tmp;
        }
    }
} 