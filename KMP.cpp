#include "iostream"
#include "String"

using namespace std;

// brute-force string matching 暴力匹配字符串
int BFSM(string s, string t)
{
    int i = 0, j = 0;
    while (s[i] != '\0' && t[j] != '\0')
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (t[j] == '\0')
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

// 记录回溯点
void getNext(int next[], string t)
{
    int j = 0, k = -1;
    next[0] = -1; // next[j] = k;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int main()
{
    string t = "abc";
    string s = "sdfdsabcabcd";
    cout << BFSM(s, t);
}
