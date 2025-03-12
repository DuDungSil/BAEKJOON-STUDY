// 14500 테트로미노
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 다 해봐야함
// dfs

int N, M;
int arr[502][502];
bool visited[502][502];
int max_num = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int depth, int sum)
{
    if(depth == 3) 
    {
        max_num = max(max_num, sum);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_y < 0 || new_x > N || new_y > M) continue;
        if(visited[new_x][new_y] == true) continue;

        visited[new_x][new_y] = true;
        dfs(new_x, new_y, depth + 1, sum + arr[new_x][new_y]);
        visited[new_x][new_y] = false;
    }

}

int main(void) 
{

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    // dfs
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 0, arr[i][j]);
            visited[i][j] = false;
        }
    }

    // ㅗ 모양 체크
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int cross_sum = arr[i][j] + arr[i+1][j] + arr[i-1][j] + arr[i][j+1] + arr[i][j-1];
            for (int k = 0; k < 4; k++)
            {
                int sum = cross_sum - arr[i + dx[k]][j + dy[k]];
                max_num = max(max_num, sum);
            }
        }
    }

    cout << max_num;

    return 0;
}