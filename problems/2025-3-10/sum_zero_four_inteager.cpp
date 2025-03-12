// 7453 합이 0인 네 정수
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 이분탐색?

int main(void) 
{

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> A;
    vector<int> B;
    vector<int> C;
    vector<int> D;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    // c, d 합 전처리
    vector<int> CD;
    for(int c = 0; c < n; c++)
    {
        for(int d = 0; d < n; d++)
        {
            int sum = C[c] + D[d];
            CD.push_back(sum);
        }
    }
    
    sort(CD.begin(), CD.end());

    long long _count = 0;
    for (int a = 0; a < n; a++)
    {
        int num_a = A[a];
        for (int b = 0; b < n; b++)
        {
            int num_b = B[b];

            int ab = num_a + num_b;

            long long count = upper_bound(CD.begin(), CD.end(), -1 * ab) - lower_bound(CD.begin(), CD.end(), -1 * ab);

            _count += count;
        }

    }

    cout << _count;

    return 0;
}