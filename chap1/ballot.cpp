#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 10

int n, m;
int kk[MAX_N * MAX_N];

bool binary_search(int x)
{
    int lo = 0, hi = MAX_N * MAX_N - 1;
    while (lo < hi)
    {
        // 防止 hi 和 lo 相加溢出
        int d = (hi - lo) >> 1;

        // 处理 1/2 = 0 的问题 TODO 写得太不自然了，奇怪的写法!
        if (lo == MAX_N * MAX_N - 2)
        {
            d = 1;
        }
        if (hi == 1)
        {
            d = 0;
        }

        int mid = lo + d;

        printf("%d  %d  %d\n", lo, mid, hi);

        if (x > kk[mid])
        {
            lo = mid;
        }
        else if (x < kk[mid])
        {
            hi = mid;
        }
        else
        {
            return true;
        }
    }

    return false;
}

void solve(int k[])
{
    for (int c = 0; c < n; c++)
    {
        for (int d = 0; d < n; d++)
        {
            // 枚举的结果含有重复，但是这里不管它
            kk[c * n + d] = k[c] + k[d];
        }
    }

    // 按倒序排个序
    sort(kk, kk + n * n);

    bool f = false;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            // 如果能得出 m - k[a] - k[b] = k[c] + k[d]
            // 这样的m值就是我们想要的
            if (binary_search(m - k[a] - k[b]))
            {
                f = true;
                break;
            }
        }
    }

    if (f)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
}

int main()
{
    m = 140, n = 10;
    int k[MAX_N] = {2, 3, 4, 5, 10, 2, 3, 4, 5, 6};
    solve(k);

    m = 14;
    solve(k);
}