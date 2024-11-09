#include <iostream>
#include <string>
#define MAXN 1000005
using namespace std;

string s1, s2;
int KMP[MAXN];

int main() {
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();

    KMP[0] = 0;
    for (int i = 1, j = 0; i < len2; i++) {
        while (j > 0 && s2[i] != s2[j]) {
            j = KMP[j - 1];
        }
        if (s2[i] == s2[j]) {
            j++;
        }
        KMP[i] = j;
    }

    for (int i = 0, j = 0; i < len1; i++) {
        while (j > 0 && s1[i] != s2[j]) {
            j = KMP[j - 1];
        }
        if (s1[i] == s2[j]) {
            j++;
        }
        if (j == len2) {
            cout << i - len2 + 2 << endl;
            j = KMP[j - 1];
        }
    }

    for (int i = 0; i < len2; i++) {
        cout << KMP[i] << " ";
    }
    cout << endl;

    return 0;
}
