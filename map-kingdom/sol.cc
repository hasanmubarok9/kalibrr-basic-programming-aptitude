#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        int N, M;
        cin >> N >> M;

        vector<string> grid(N);
        for (int i = 0; i < N; ++i)
            cin >> grid[i];

        vector<vector<bool>> vis(N, vector<bool>(M, false));
        vector<int> controlled(26, 0);
        int contested = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (vis[i][j] || grid[i][j] == '#')
                    continue;

                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;

                set<char> letters;

                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();

                    if (grid[r][c] >= 'a' && grid[r][c] <= 'z')
                    {
                        letters.insert(grid[r][c]);
                    }

                    for (int k = 0; k < 4; ++k)
                    {
                        int nr = r + dr[k], nc = c + dc[k];
                        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                            continue;
                        if (vis[nr][nc] || grid[nr][nc] == '#')
                            continue;
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }

                if (letters.size() == 1)
                {
                    controlled[*letters.begin() - 'a']++;
                }
                else if (letters.size() >= 2)
                {
                    contested++;
                }
            }
        }

        cout << "Case " << tc << ":\n";
        for (int i = 0; i < 26; ++i)
        {
            if (controlled[i] > 0)
            {
                cout << char('a' + i) << " " << controlled[i] << "\n";
            }
        }
        cout << "contested " << contested << "\n";
    }

    return 0;
}