#include <stdio.h>
#define MAX_N 1000000 // the count of ants
using namespace std;

int L, n;
int a[MAX_N];

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

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void solution()
{

    int minT = 0;
    for (int i = 0; i < n; i++)
    {
        // min 求一只蚂蚁掉落需要的最少秒，max 求所有蚂蚁掉落需要的最少秒
        minT = max(minT, min(a[i], L - a[i]));
    }

    int maxT = 0;
    for (int i = 0; i < n; i++)
    {
        maxT = max(maxT, max(a[i], L - a[i]));
    }

    printf("%d %d\n", minT, maxT);
}

int main()
{
    int caseNum;
    scanf("%d", &caseNum);

    while (caseNum--)
    {
        scanf("%d%d", &L, &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        solution();
    }
    return 0;
}