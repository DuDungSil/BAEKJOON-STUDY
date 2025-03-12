// 1197 최소 스패닝 트리
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

// 스패닝 트리 : 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치 합이 최소인 트리
// 벨만 포드 알고리즘에서 간선 선택 알고리즘만

int V, E;
vector<tuple<int, int, int>> graph;
vector<int> unions;

int find(int v)
{
    if(v == unions[v])
        return v;
    return unions[v] = find(unions[v]);
}

bool make_union(int v1, int v2)
{
    int a = find(v1);
    int b = find(v2);
    if(a != b) 
    {
        unions[b] = a;
        return true;
    }
    else
        return false;
}


bool compare(tuple<int, int, int> &a, tuple<int, int, int>& b)
{
    return get<2>(a) < get<2>(b);
}

long long cruscal()
{
    // 가중치 오름차순 정렬
    sort(graph.begin(), graph.end(), compare);

    int edges = 0;
    long long sum = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        int u, v, w;
        tie(u, v, w) = graph[i];
        // 사이클 체크
        if(make_union(u, v))
        {
            edges++;
            sum += w;
        }

        // v - 1 개 간선 선택시 종료
        if(edges == V - 1)
        {
            break;
        }
    }

    return sum;
}

int main(void) 
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    unions = vector<int>(V + 1);

    for (int i = 1; i <= V; i++)
    {
        unions[i] = i;
    }

    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        graph.push_back({A, B, C});
    }

    long long min_w = cruscal();

    cout << min_w;



    return 0;
}