// 2239 스도쿠
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 무조건 정답이 정해져있는 칸 부터 채우기
// 나머지 백트래킹?

// 0인 모든 칸에 가능한 수를 생각
// 가능한 수가 적은 칸부터 배치

// 조건 확인 1. 부분 9칸
//          2. 행
//          3. 열

int sudoku[10][10] = { 0,};
vector<pair<int, int>> empty_cells;

bool check(int x, int y, int num)
{

    for (int k = 1; k <= 9; k++)
    {
        if(sudoku[x][k] == num || sudoku[k][y] == num)
            return false;
    }

    // 부분 칸 체크
    int x_offset = (x - 1) / 3;
    int y_offset = (y - 1) / 3;
    for (int k = 1; k <= 3; k++)
    {
        for (int l = 1; l <= 3; l++)
        {
            if(sudoku[x_offset * 3 + k][y_offset * 3 + l] == num)
                return false;
        }
    }

    return true;
}

void back_tracking(int idx)
{
    // 탈출
    if(idx == empty_cells.size())
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << sudoku[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }

    int x = empty_cells[idx].first;
    int y = empty_cells[idx].second;

    // 백트래킹
    for (int i = 1; i <= 9; i++)
    {
        if (check(x, y, i))
        {
            sudoku[x][y] = i;
            back_tracking(idx + 1);
            sudoku[x][y] = 0;
        }
    }

}

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int total = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            char c;
            cin >> c;
            sudoku[i][j] = int(c - '0');
            if(sudoku[i][j] == 0) empty_cells.push_back({i, j});
        }
    }

    back_tracking(0);

    return 0;
}