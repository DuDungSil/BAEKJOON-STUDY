// 1967 트리의 지름
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 항상 트리의 맨끝 노드 찾기

bool visited[10001] = {
    false,
};

int big_cost = -1;

void dfs(vector<vector<pair<int, int>>>& tree, vector<bool>& leafs, int start, int now, int cost)
{

    if( now != start && leafs[now] )
    {
        big_cost = max(big_cost, cost);
        return;
    }

    for (int i = 0; i < tree[now].size(); i++)
    {
        pair<int, int> info = tree[now][i];
        int next = info.first;
        int next_cost = info.second;

        if(!visited[next])
        {
            visited[next] = true;
            dfs(tree, leafs, start, next, cost + next_cost);
            visited[next] = false;
        } 
    }

    return;
}

int main(void) 
{

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> tree(n+1, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++)
    {
        int m, c, w;
        cin >> m >> c >> w;
        tree[m].push_back({c, w});
        tree[c].push_back({m, w});
    }

    // 리프노드 찾기
    vector<bool> leafs(n+1, false);
    for (int i = 1; i <= n; i++)
    {
        if(tree[i].size() == 1)
        {
            leafs[i] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // dfs
        if(leafs[i])
        {
            visited[i] = true;
            dfs(tree, leafs, i, i, 0);
            visited[i] = false;
        } 
    }

    if (n == 1)
    {
        cout << 0;
    }
    else
    {
        cout << big_cost;
    }

    return 0;
}