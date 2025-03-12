// 1647 도시 분할 계획
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

// 도시를 두 도시로 분리하면서 필요없는 길 제거
// 항상 임의의 두 경로 존재 필요

int N, M;
vector<int> parent;
vector<tuple<int, int, int>> graph;

int find(int v)
{
    if(v != parent[v])
        return parent[v] = find(parent[v]);
    else
        return v;
}

bool make_union(int v1, int v2)
{
    int a = find(v1);
    int b = find(v2);

    if(a != b) 
    {
        parent[a] = b;
        return true;
    }
    else
        return false;
}

bool compare(tuple<int, int, int>& a, tuple<int, int, int>& b)
{
    return get<2>(a) < get<2>(b);
}

int cruscal()
{

    sort(graph.begin(), graph.end(), compare);

    int edges = 0;
    int sum = 0;
    int big_w = -1;
    for (int i = 0; i < graph.size(); i++)
    {
        int u, v, w;
        tie(u, v, w) = graph[i];
        if(make_union(u, v))
        {
            edges++;
            sum += w;
            big_w = max(big_w, w);
        }

        if(edges == N - 1)
        {
            break;
        }
    }

    return sum - big_w;
}

int main(void) 
{


    cin >> N >> M;

    parent = vector<int>(N + 1);

    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph.push_back({a, b ,c});
    }

    int answer = cruscal();

    cout << answer;


    return 0;
}