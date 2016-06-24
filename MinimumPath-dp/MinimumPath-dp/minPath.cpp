#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
    int n = grid[0].size();


	// minPathSum[i][j] defines the minimum path cost from the origin grid[0][0] to the destination grid[i][j]
	int** minPathSum = new int* [m]; 
	for (int i = 0; i < m;i++) {
		minPathSum[i] = new int[n];
	}

	minPathSum[0][0] = grid[0][0];
	for (int i = 1; i < n;i++) {

		minPathSum[0][i] = minPathSum[0][i - 1]+grid[0][i];
	}
	for (int i = 1; i < m;i++) {

		minPathSum[i][0] = minPathSum[i-1][0] + grid[i][0];
	}

	for (int i = 1; i < m;i++) {
		for (int j = 1; j < n;j++) {
			minPathSum[i][j] = min(minPathSum[i-1][j],minPathSum[i][j-1]);
			minPathSum[i][j] += grid[i][j];
		}
	}

	return minPathSum[m-1][n-1];



}

void main() {}