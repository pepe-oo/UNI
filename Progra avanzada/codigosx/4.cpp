#include <iostream>
#include <vector>
#define MAX 100

void solve(int r, int c, int n, int m, int& count, int grid[][MAX], bool visited[][MAX])
{
    if (r == n - 1 && c == m - 1)
    {
        count++;
        return;
    }
    if (r + 1 < n && grid[r + 1][c] != 1 && visited[r + 1][c] != 1)
    {
        visited[r + 1][c] = 1;
        solve(r + 1,c,n,m,count,grid,visited);
        visited[r + 1][c] = 0;
    }
    if (r - 1 >= 0 && r - 1 < n && grid[r - 1][c] != 1 && visited[r - 1][c] != 1)
    {
        visited[r - 1][c] = 1;
        solve(r - 1,c,n,m,count,grid,visited);
        visited[r - 1][c] = 0;
    }
    if (c + 1 < m && grid[r][c + 1] != 1 && visited[r][c + 1] != 1)
    {
        visited[r][c + 1] = 1;
        solve(r,c + 1,n,m,count,grid,visited);
        visited[r][c + 1] = 0;
    }
    if (c - 1 >= 0 && c - 1 < m && grid[r][c - 1] != 1 && visited[r][c - 1] != 1)
    {
        visited[r][c - 1] = 1;
        solve(r,c-1,n,m,count,grid,visited);
        visited[r][c - 1] = 0;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    int grid[MAX][MAX];
    bool visited[MAX][MAX] = {};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> grid[i][j];
    int count = 0;
    visited[0][0] = 1;
    solve(0, 0, n, m, count, grid, visited);
    std::cout << count << std::endl;
    return 0;
}