// 20040 사이클 게임
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 유니온 파인드

int N, M;
vector<int> union_A;

int find(vector<int> &arr, int v)
{
    if(arr[v] != v)
    {
        return arr[v] = find(arr, arr[v]);
    }
    else
        return v;
}

bool make_union(vector<int> &arr, int v1, int v2)
{
    int a = find(arr, v1);
    int b = find(arr, v2);

    if(a != b)
    {
        arr[a] = b;
        return true;
    }
    else
        return false;
}

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> N >> M;

    union_A = vector<int>(N);

    for(int i = 0; i < N; i++)
    {
        union_A[i] = i;
    }

    int exit_turn = 0;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;

        if(!make_union(union_A, a, b) && exit_turn == 0)
        {
            exit_turn = i;
        }

    }

    cout << exit_turn;

    return 0;
}