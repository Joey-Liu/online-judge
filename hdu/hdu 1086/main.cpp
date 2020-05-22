#include <iostream>

using namespace std;

const double eps = 1e-8;
const int maxn = 200 + 10;

int sgn(double t) {
    if (t < -eps) {
        return -1;
    } else if (t > eps) {
        return 1;
    } else {
        return 0;
    }
}

struct Point {
    double x, y;
};

double dot(Point p, Point q) {
    return p.x * q.x + p.y + q.y;
}

double chaji(Point p, Point q) {
    return p.x * q.y - q.x * p.y;
}

bool on_seg(Point a, Point b, Point c) {
    Point p;
    p.x = a.x - b.x;
    p.y = a.y - b.y;
    Point q;
    q.x = a.x - c.x;
    q.y = a.y - c.y;

    return sgn(chaji(p, q)) == 0 && sgn(dot(p, q)) <= 0;
}

bool two_side(Point a, Point b, Point c, Point d) {
    Point p;
    p.x = c.x - a.x;
    p.y = c.y - a.y;
    Point q;
    q.x = d.x - a.x;
    q.y = d.y - a.y;

    Point ff;
    ff.x = b.x - a.x;
    ff.y = b.y - a.y;

    return sgn(chaji(ff, p)) * sgn(chaji(ff, q)) < 0;
}

bool insect(Point a, Point b, Point c, Point d) {
    if (on_seg(a, c, d) || on_seg(b, c, d) || on_seg(c, a, b) || on_seg(d, a, b)) {
        return true;
    }

    if (two_side(a, b, c, d) && two_side(c, d, a, b)) {
        return true;
    }
    return false;
}

Point starts[maxn], endss[maxn];
int N;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (cin >> N && N) {
        for (int i = 0; i < N; i++) {
            cin >> starts[i].x >> starts[i].y;
            cin >> endss[i].x >> endss[i].y;
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                if (insect(starts[i], endss[i], starts[j], endss[j])) {
                    res++;
                }
            }//for int j
        }// for int i
        cout << res / 2 << endl;

    }// cin >> N
    return 0;
}