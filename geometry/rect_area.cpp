#define sz(x) (int(x.size()))

const int MAX_NN = (1 << 17);

struct Rect {
    double x1, y1, x2, y2;
};

struct Event {
    double y; int x1, x2, type;
    bool operator < (const Event& e) const {
        if (y == e.y)
            return type < e.type;
        return y < e.y;
    }
};

vector<double> xs;

struct SegTree {
    int NN;
    int cnt[MAX_NN];
    double len[MAX_NN];

    void init(int n) {
        NN = 1;
        while (NN < n)
            NN <<= 1;
        fill(cnt, cnt + 2 * NN, 0);
        fill(len, len + 2 * NN, double(0.0));
    }

    void maintain(int u, int l, int r) {
        if (cnt[u] > 0) len[u] = xs[r] - xs[l];
        else {
            if (u >= NN - 1)
                len[u] = 0;
            else
                len[u] = len[u * 2 + 1] + len[u * 2 + 2];
        }
    }

    void update(int a, int b, int x, int u, int l, int r) { // [a, b), [l, r)
        if (r <= a || l >= b) return;
        if (a <= l && r <= b) {
            cnt[u] += x;
            maintain(u, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, x, u * 2 + 1, l, m);
        update(a, b, x, u * 2 + 2, m, r);
        maintain(u, l, r);
    }
};

double get_union_area(const vector<Rect>& rect) {
    // 離散化 x
    xs.clear();
    for (int i = 0; i < sz(rect); i++) {
        xs.push_back(rect[i].x1);
        xs.push_back(rect[i].x2);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    // sweep line events
    vector<Event> es;
    for (int i = 0; i < sz(rect); i++) {
        int x1 = lower_bound(xs.begin(), xs.end(), rect[i].x1) - xs.begin();
        int x2 = lower_bound(xs.begin(), xs.end(), rect[i].x2) - xs.begin();
        es.push_back((Event) {rect[i].y1, x1, x2, +1}); // bottom
        es.push_back((Event) {rect[i].y2, x1, x2, -1}); // top
    }
    sort(es.begin(), es.end());

    // find total area
    SegTree seg;
    seg.init(sz(xs));
    seg.update(es[0].x1, es[0].x2, es[0].type, 0, 0, seg.NN);

    double res = 0;
    for (int i = 1; i < sz(es); i++) {
        res += seg.len[0] * (es[i].y - es[i - 1].y);
        seg.update(es[i].x1, es[i].x2, es[i].type, 0, 0, seg.NN);
    }

    return res;
}
