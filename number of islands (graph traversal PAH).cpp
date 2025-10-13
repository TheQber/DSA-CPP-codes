/*
 * Number of Islands Problem (Graph Traversal PAH)
 * 
 * This program counts the number of islands in a 2D grid where islands are connected
 * regions of 1s (land) surrounded by 0s (water). It uses DFS (Depth-First Search) to
 * explore each island completely before moving to the next one. The algorithm uses
 * 4-directional movement to connect adjacent land cells and marks visited cells to
 * avoid counting the same island multiple times. Input consists of grid dimensions
 * (n, m) followed by the grid as strings of 0s and 1s. Output displays the total
 * number of islands in the grid.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dRow[4] = {-1, 1, 0, 0};  // up, down, left, right
int dCol[4] = {0, 0, -1, 1};

bool inBounds(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void dfs(int r, int c) {
    visited[r][c] = true;
    for (int k = 0; k < 4; k++) {
        int nr = r + dRow[k];
        int nc = c + dCol[k];
        if (inBounds(nr, nc) && !visited[nr][nc] && grid[nr][nc] == 1) {
            dfs(nr, nc);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count;
    return 0;
}
