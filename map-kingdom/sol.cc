#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> controlled(26, 0); // Count of cells controlled by each kingdom
        int contested = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '#' || visited[i][j])
                    continue;

                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                set<char> letters;
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    if (grid[x][y] >= 'a' && grid[x][y] <= 'z')
                    {
                        letters.insert(grid[x][y]);
                    }

                    for (int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny])
                        {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                if (letters.size() == 1)
                {
                    controlled[*letters.begin() - 'a']++;
                }
                else if (letters.size() > 1)
                {
                    contested++;
                }
            }
        }

        cout << "Case " << tc + 1 << ":\n";
        for (int i = 0; i < 26; i++)
        {
            if (controlled[i] > 0)
            {
                cout << char('a' + i) << " " << controlled[i] << "\n";
            }
        }
        cout << "contested " << contested << "\n";
    }
}