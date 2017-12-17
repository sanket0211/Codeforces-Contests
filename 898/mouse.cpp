int isPath(int **grid,int m,int n){
	return solve(grid,0,0,m,n);
}
int Solve(int **grid,x,y,m,n){
	if(x>=0 && x < m && y>=0 && y<n){
		if(grid[x][y]==9){
			return 1;
		}
		if(grid[x][y] == 1)
		{
			
			if (solve(grid, x+1, y, m,n) == 1)
				return 1;
					
			if (solve(grid, x, y+1, m,n) == 1)
				return 1;
							
			return 0;
		}
		return 0;
	}
	return 0;
}
