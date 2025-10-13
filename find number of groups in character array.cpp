/*
 * Find Number of Connected Groups in Character Array
 * 
 * This program finds the number of connected components (groups) in a 2D character grid
 * using DFS (Depth-First Search). Each group consists of adjacent cells containing
 * the same character. The algorithm uses 4-directional movement (up, down, left, right)
 * to explore connected regions and marks visited cells to avoid counting them multiple times.
 * Input consists of grid dimensions (n, m) followed by the character grid.
 * Output displays the total number of connected groups in the grid.
 */

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<string> grid;
bool visited[10][10];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, char ch) {
    visited[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny] && grid[nx][ny] == ch) {
                dfs(nx, ny, ch);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    int components = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j]);
                components++;
            }
        }
    }

    cout << components;
    return 0;
}
