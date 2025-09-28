#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000001;
int n, m, c, seq[maxn];
class deque_t {
private:
        int item[maxn], tfront, tback;
public:
        deque_t() {
                tfront = tback = 0;
        }
        void push_back(int tkey) {
                item[++tback] = tkey;
        }
        void pop_front() {
                ++tfront;
        }
        void pop_back() {
                --tback;
        }
        int front() const {
                return item[tfront + 1];
        }
        int back() const {
                return item[tback];
        }
        int empty() const {
                return (tfront == tback);
        }
};

class monoque_t {
private:
        int is_up;
        deque_t dq;
public:
        monoque_t(int tis_up) {
                is_up = tis_up;
        }
        int pop_front(int front) {
                while (dq.front() < front) {
                        dq.pop_front();
                }
                return seq[dq.front()];
        }
        void push_back(int key) {
                if (is_up) {
                        while (!dq.empty() && seq[dq.back()] < seq[key]) {
                                dq.pop_back();
                        }
                } else {
                        while (!dq.empty() && seq[dq.back()] > seq[key]) {
                                dq.pop_back();
                        }
                }
                dq.push_back(key);
        }
} *monoque1, *monoque2;

int main() {
        int result = 0;
        scanf("%d%d%d", &n, &m, &c);
        for (int i = 1; i <= n; ++i) {
                scanf("%d", &seq[i]);
        }
        monoque1 = new monoque_t(true), monoque2 = new monoque_t(false);
        for (int i = 1; i <= m; ++i) {
                monoque1->push_back(i);
                monoque2->push_back(i);
        }
        for (int front = 1; front <= n - m + 1; ++front) {
                if (monoque1->pop_front(front) - monoque2->pop_front(front) <= c) {
                        ++result;
                        printf("%d\n", front);
                }
                if (front != n - m + 1) {
                        monoque1->push_back(front + m), monoque2->push_back(front + m);
                }
        }
        if (!result) {
                puts("NONE");
        }
        return 0;
}
