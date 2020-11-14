#include "iostream"
#include "string"

using namespace std;

// brute-force string matching 暴力匹配字符串
int BFSM(string s, string t) {
    int i = 0, j = 0;
    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (t[j] == '\0') {
        return i - j;
    } else {
        return -1;
    }
}

// 记录公共前后缀最长长度
void getNext(int next[], string t) {
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.length() - 1) {
        if (k == -1 || t[j] == t[k]) {
            j++;
            k++;
            next[j] = k; // 下面的else语句有暂存next元素值的作用，所以这里next[j]实际等于 next[k-1] + 1
        } else {
            k = next[k];
        }
    }
}

int KMP(string s, string p) {
    int next[p.size()];
    getNext(next, p);

    int i = 0, j = 0;
    while (s[i] != '\0' && p[j] != '\0') {
        if (s[i] != p[j]) {
            // i不回溯，只前进不后退
            i += (j - next[j]);
            j = 0;
            continue;
        } else if (j == p.size() - 1)
            return i - j;
        i++;
        j++;
    }
    return -1;
}

int main() {
    string t = "abc";
    string s = "sdfdsabcabcd";
    cout << BFSM(s, t) << endl;

    int next[3];
    getNext(next, t);
    int size = sizeof(next) / sizeof(next[1]);
    for (int i = 0; i < size; i++) {
        cout << next[i] << "  ";
    }
    cout << endl;

    cout << KMP(s, t) << endl;
}
