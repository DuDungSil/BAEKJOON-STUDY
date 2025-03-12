// 17144 미세먼지 안녕!
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 공기청정기 항상 1번 열

// 1초
// 미세먼지 확산 : 4방향, 인접한 방향에 공기 청정기 있거나, 칸이 없으면 그 방향 확산 X
//                확산양 A / 5 , 남은 양 A - A / 5 * 확산 수

// 공기청정기 작동 : 위쪽 - 바람 반시계방향 순환
//                  아래쪽 - 바람 시계방향 순환
//                 바람 불면 미세먼지가 바람 방향대로 모두 한칸씩 이동
//                 공기청정기로 들어간 미세먼지는 정화

// T초가 지난 후 구사과 방에 남아있는 미세먼지 양

int R, C, T;
int top_cleaner = -1;
int bottom_cleaner = -1;
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

void diffuse(vector<vector<int>> &room)
{
    vector<vector<int>> tmp(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int sum = 0;
            int sum_count = 0;
            for (int k = 0; k < 4; k++)
            {
                int diff_x = j + dx[k];
                int diff_y = i + dy[k];
                if(diff_x >= 0 && diff_y >= 0 && diff_x < C && diff_y < R && room[diff_y][diff_x] != -1)
                {
                    sum += room[diff_y][diff_x] / 5;
                    sum_count++;
                }
            }
            tmp[i][j] = sum + room[i][j] - room[i][j] / 5 * sum_count;
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            room[i][j] = tmp[i][j];
        }
    }
}

void clean(vector<vector<int>> &room)
{
    vector<vector<int>> tmp(R, vector<int>(C, 0));

    // 위쪽
    for (int i = 0; i <= top_cleaner; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // 맨 위
            if(i == 0 && j != C - 1)
            {
                tmp[i][j] = room[i][j + 1];
            }
            // 맨 오른쪽
            else if(j == C - 1 && i != top_cleaner)
            {
                tmp[i][j] = room[i+1][j];
            }
            // 맨 왼쪽
            else if(j == 0 && i != 0)
            {
                tmp[i][j] = room[i-1][j];
            }
            // 맨 아래
            else if(i == top_cleaner && j != 0)
            {
                tmp[i][j] = room[i][j-1];
            }
            else
            {
                tmp[i][j] = room[i][j];
            }
        }
        tmp[top_cleaner][0] = -1;
        tmp[top_cleaner][1] = 0;
    }

    // 아래쪽
    for (int i = bottom_cleaner; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // 맨 왼쪽
            if(j == 0 && i != R - 1)
            {
                tmp[i][j] = room[i+1][j];
            }
            // 맨 오른쪽
            else if(j == C - 1 && i != bottom_cleaner)
            {
                tmp[i][j] = room[i-1][j];
            }

            // 맨 위
            else if(i == bottom_cleaner && j != 0)
            {
                tmp[i][j] = room[i][j - 1];
            }

            // 맨 아래
            else if(i == R - 1 && j != C - 1)
            {
                tmp[i][j] = room[i][j + 1];
            }
            else
            {
                tmp[i][j] = room[i][j];
            }
        }
        tmp[bottom_cleaner][0] = -1;
        tmp[bottom_cleaner][1] = 0;
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            room[i][j] = tmp[i][j];
        }
    }
}

int main(void) 
{

    cin >> R >> C >> T;

    vector<vector<int>> room(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int num;
            cin >> num;
            room[i][j] = num;
            if(num == -1 && top_cleaner == -1)
            {
                top_cleaner = i;
            }
            else if(num == -1 && bottom_cleaner == -1)
            {
                bottom_cleaner = i;
            }
        }
    }

    // 시간
    for (int t = 1; t <= T; t++)
    {
        // 미세먼지 확산
        diffuse(room);

        // 공기청정기 작동
        clean(room);
    
    }

    // 총합
    int sum = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if(room[i][j] != -1) sum += room[i][j];
        }
    }

    cout << sum;


    return 0;
}