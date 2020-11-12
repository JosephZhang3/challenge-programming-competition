#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 5

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/**
 * 暴力解法
 */
void solutionBruteForce(int n, int a[])
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int len = a[i] + a[j] + a[k];
                int maxone = max(a[i], max(a[j], a[k]));
                int rest = len - maxone;

                if (rest > maxone)
                {
                    ans = max(ans, len);
                }
            }
        }
    }

    printf("%d\n", ans);
}

/**
 * 降序算法
 */
bool comp(int a, int b)
{
    return a > b;
}

/**
O(nlogn) 解法
*/
void solationBest(int n, int a[])
{
    // 按倒序排个序
    sort(a, a + sizeof(&a) / sizeof(a[0]), comp);

    int ans = 0;

    for (int i = 1; i < n - 2; i++)
    {
        // 两短边 大于 最长边
        if (a[i + 2] + a[i + 1] > a[i])
        {
            // 只取第一次满足条件的三边，记录周长然后跳出循环
            ans = a[i] + a[i + 1] + a[i + 2];
            break;
        }
    }

    printf("%d\n", ans);
}

/**
 * 给定若干条边组成三角形，求能成功组成的三角形的最大周长 
条件：两边之和大于第三边
*/
int main()
{
    int n = 5;
    int a[MAX_N] = {2, 3, 4, 5, 10};
    // solutionBruteForce(n, a);
    solationBest(n, a);

    return 0;
}
