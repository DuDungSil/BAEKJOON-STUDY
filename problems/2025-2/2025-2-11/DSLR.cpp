#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// D : n을 두배로 바꿈 % 10000
// S : b - 1 저장    n == 0, n = 9999
// L : 왼편 회전
// R : 오른편 회전

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int prev, result;
        cin >> prev >> result;

        bool visited[10000] = {false, };

        queue<pair<int, string>> q;

        q.push({prev, ""});
        visited[prev] = true;

        while (!q.empty()) {
            pair<int, string> info = q.front();
            q.pop();

            int now = info.first;
            string ops = info.second;

            if (now == result) {
                cout << ops << "\n";
                break;
            }

            // D
            int next_d = (2 * now) % 10000;
            if (!visited[next_d]) {
                visited[next_d] = true;
                string new_ops = ops + "D";
                q.push({next_d, new_ops});
            }

            // S
            int next_s = (now == 0) ? 9999 : now - 1;
            if (!visited[next_s]) {
                visited[next_s] = true;
                string new_ops = ops + "S";
                q.push({next_s, new_ops});
            }

            // L
            int next_l = (now % 1000) * 10 + now / 1000 ;
            if (!visited[next_l]) {
                visited[next_l] = true;
                string new_ops = ops + "L";
                q.push({next_l, new_ops});
            }

            // R
            int next_r = (now % 10) * 1000 + now / 10;
            if (!visited[next_r]) {
                visited[next_r] = true;
                string new_ops = ops + "R";
                q.push({next_r, new_ops});
            }
        }
    }

    return 0;
}
