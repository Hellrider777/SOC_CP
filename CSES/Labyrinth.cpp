#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

int dx[4] = {-1, 1, 0, 0}; // Up, Down, Left, Right
int dy[4] = {0, 0, -1, 1};
char d[4] = {'U', 'D', 'L', 'R'};

bool is_valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m &&
           (grid[x][y] == '.' || grid[x][y] == 'B') && !visited[x][y];
}

bool bfs(int sx, int sy, int ex, int ey)
{
    queue<pair<int, int>> q;
    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == ex && y == ey)
            return true;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (is_valid(nx, ny))
            {
                visited[nx][ny] = true;
                parent[nx][ny] = make_pair(x, y);
                q.push(make_pair(nx, ny));
            }
        }
    }

    return false;
}

string reconstruct_path(int sx, int sy, int ex, int ey)
{
    string path = "";
    int x = ex, y = ey;
    while (make_pair(x, y) != make_pair(sx, sy))
    {
        int px = parent[x][y].first;
        int py = parent[x][y].second;

        for (int dir = 0; dir < 4; dir++)
        {
            if (px + dx[dir] == x && py + dy[dir] == y)
            {
                path += d[dir];
                break;
            }
        }

        x = px;
        y = py;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m));

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'B')
            {
                ex = i;
                ey = j;
            }
        }
    }

    if (bfs(sx, sy, ex, ey))
    {
        string path = reconstruct_path(sx, sy, ex, ey);
        cout << "YES\n";
        cout << path.length() << "\n";
        cout << path << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
