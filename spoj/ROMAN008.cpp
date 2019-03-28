#include <cstdio>
#include <cstring>

int pa(int d, int ln, int ld) {
    if (ln > d) return ld - d;
    else return ld + d;
}
int rtd(char * r) {
    int d = 0;
    int ln = 0;
    int len = strlen(r);
    for (int c = len - 1; c >= 0; c--) {
        switch (r[c]) {
            case 'M':
                d = pa(1000, ln, d);
                ln = 1000;
                break;
            case 'D':
                d = pa(500, ln, d);
                ln = 500;
                break;
            case 'C':
                d = pa(100, ln, d);
                ln = 100;
                break;
            case 'L':
                d = pa(50, ln, d);
                ln = 50;
                break;
            case 'X':
                d = pa(10, ln, d);
                ln = 10;
                break;
            case 'V':
                d = pa(5, ln, d);
                ln = 5;
                break;
            case 'I':
                d = pa(1, ln, d);
                ln = 1;
                break;
        }
    }
    return d;
}
int main() {
    char r1[256], r2[256], op[2], res[256];
    int a, b, c, n, it;
    while (scanf("%s %s %s", r1, r2, op) != EOF) {
        a = rtd(r1);
        b = rtd(r2);
        switch (op[0]) {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                c = a / b;
                break;
            case '%':
                c = a % b;
                break;
            default:
                break;
        }
        n = 0;
        while (c != 0) {
            if (c >= 1000) {
                it = c / 1000;
                for (int i = 0; i < it; i++) res[n++] = 'M';
                c = c - it * 1000;
            } else if (c >= 500) {
                if (c < 900) {
                    it = c / 500;
                    for (int i = 0; i < it; i++) res[n++] = 'D';
                    c = c - it * 500;
                } else {
                    res[n++] = 'C';
                    res[n++] = 'M';
                    c = c - 900;
                }
            } else if (c >= 100) {
                if (c < 400) {
                    it = c / 100;
                    for (int i = 0; i < it; i++) res[n++] = 'C';
                    c = c - it * 100;
                } else {
                    res[n++] = 'L';
                    res[n++] = 'D';
                    c = c - 400;
                }
            } else if (c >= 50) {
                if (c < 90) {
                    it = c / 50;
                    for (int i = 0; i < it; i++) res[n++] = 'L';
                    c = c - it * 50;
                } else {
                    res[n++] = 'X';
                    res[n++] = 'C';
                    c = c - 90;
                }
            } else if (c >= 10) {
                if (c < 40) {
                    it = c / 10;
                    for (int i = 0; i < it; i++) res[n++] = 'X';
                    c = c - it * 10;
                } else {
                    res[n++] = 'X';
                    res[n++] = 'L';
                    c = c - 40;
                }
            } else if (c >= 5) {
                if (c < 9) {
                    it = c / 5;
                    for (int i = 0; i < it; i++) res[n++] = 'V';
                    c = c - it * 5;
                } else {
                    res[n++] = 'I';
                    res[n++] = 'X';
                    c = c - 9;
                }
            } else if (c >= 1) {
                if (c < 4) {
                    it = c;
                    for (int i = 0; i < it; i++) res[n++] = 'I';
                    c = c - it * 1;
                } else {
                    res[n++] = 'I';
                    res[n++] = 'V';
                    c = c - 4;
                }
            }
        }
        res[n] = '\0';
        puts(res);
    }
    return 0;
}
