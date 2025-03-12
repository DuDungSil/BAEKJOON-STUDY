// 2166 다각형의 면적
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long double ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    pair<long double, long double> v1 = {b.first - a.first, b.second - a.second};
    pair<long double, long double> v2 = {c.first - a.first, c.second - a.second};

    // 외적
    return v1.first * v2.second - v1.second * v2.first;
}

int main(void) 
{

    int N;
    cin >> N;

    vector<pair<int, int>> vertex;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        vertex.push_back({x, y});
    }

    long double sum = 0;
    for (int i = 1; i < vertex.size() - 1; i++)
    {
        sum += ccw(vertex[0], vertex[i], vertex[i + 1]);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(sum) / 2.0;


    return 0;
}