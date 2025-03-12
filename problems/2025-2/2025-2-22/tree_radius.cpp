// 1167 트리의 지름
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> visited;

int dfs(vector<vector<pair<int, int>>>& tree, int now)
{
    if(tree[now].size() == 1)
    {
        return tree[now][0].second;
    }

    for (int i = 0; i < tree.size(); i++)
    {
        pair<int, int> info = tree[now][i];
        if(!visited[info.first])
        {
            visited[info.first] = true;
            dfs(tree, info.first);
        }
    }

    return 0;
}



int main(void) 
{

    int V;
    cin >> V;

    vector<vector<pair<int, int>>> tree(V+1);
    visited = vector<bool>(V + 1, false);
    for (int i = 0; i < V; i++)
    {
        int vertex, num;
        cin >> vertex;
        while(cin >> num && num != -1)
        {
            int w;
            tree[vertex].push_back({num, w});
        }
    }

    // 리프노드 찾기
    visited[1] = true;
    dfs(tree, 1);

    // 리프노드에서 각 리프노드로의 거리의 최대값 구하기
    

    system("\npause");
    return 0;
}