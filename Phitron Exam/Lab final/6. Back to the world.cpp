// Problem link: https://lightoj.com/problem/back-to-underworld

#include <bits/stdc++.h>
using namespace std;

vector<int> vec[20009]; 
bool vis[20009] = {};
bool node_type[20009] = {};

long long int bfs(int x);


void clearing()
{
    memset(vis, false, sizeof(vis));
    memset(node_type, false, sizeof(node_type));
    for (int i = 0; i < 20009; i++)
        vec[i].clear();
}

long long int modified_bfs(int x)
{
    long long int lykan_num = 0, vampire_num = 0;
    queue<int> q;

    q.push(x);
    vis[x] = 1;
    node_type[x] = 1;
    ++lykan_num;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < vec[u].size(); i++)
        {
            int v = vec[u][i];
            if (vis[v] == 0)
            {
                q.push(v);
                vis[v] = 1;

                if (node_type[u] == 1) 
                {
                    node_type[v] = 0;
                    ++vampire_num;
                }
                else
                {
                    node_type[v] = 1;
                    ++lykan_num;
                }
            }
        }
    }

    long long int mx = max(vampire_num, lykan_num);

    return mx;
}

int main()
{
    int T, u, v, n, case_num = 1;
    scanf("%d", &T);

    while (T--)
    {
        clearing(); 

        scanf("%d", &n);
        long long int sum = 0;

        while (n--)
        {
            scanf("%d %d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        for (int i = 0; i < 20009; i++)
        {
            if (vis[i] == 0 && !vec[i].empty())
            {
                sum += modified_bfs(i);
            }
        }
        cout << "Case " << case_num++ << ": " << sum << '\n';
    }
    return 0;
}
