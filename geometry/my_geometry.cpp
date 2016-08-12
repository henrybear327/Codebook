typedef long long ll;

typedef pair<ll, ll> pt; // points are stored using long long
typedef pair<pt, pt> seg; // segments are a pair of points

#define x first
#define y second

#define EPS 1e-9

pt operator+(pt a, pt b)
{
    return pt(a.x + b.x, a.y + b.y);
}

pt operator-(pt a, pt b)
{
    return pt(a.x - b.x, a.y - b.y);
}

pt operator*(pt a, int d)
{
    return pt(a.x * d, a.y * d);
}

ll cross(pt a, pt b)
{
    return a.x * b.y - a.y * b.x;
}

int ccw(pt a, pt b, pt c)
{
    ll res = cross(b - a, c - a);
    // printf("%lld\n", res);
    if (res > 0)
        return 1;
    else if (res == 0)
        return 0;
    else
        return -1;
}

double dist(pt a, pt b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return (dx * dx + dy * dy);
}

bool overlap(seg a, seg b)
{
    // a.x -> a, a.y -> b, b.x -> c, b.y -> d
    return ccw(a.x, a.y, b.x) == 0 && ccw(a.x, a.y, b.y) == 0;
}

bool intersect(seg a, seg b)
{
    // printf("%d\n", overlap(a, b));
    if (overlap(a, b) == true) {
        double d = 0;
        d = max(d, dist(a.x, a.y));
        d = max(d, dist(a.x, b.x));
        d = max(d, dist(a.x, b.y));
        d = max(d, dist(a.y, b.x));
        d = max(d, dist(a.y, b.y));
        d = max(d, dist(b.x, b.y));

        // d > dist(a.x, a.y) + dist(b.x, b.y)
        if (d - (dist(a.x, a.y) + dist(b.x, b.y)) > EPS) 
            return false;
        return true;
    }

    // bitch man.... Equal sign..
    if (ccw(a.x, a.y, b.x) * ccw(a.x, a.y, b.y) <= 0 &&
        ccw(b.x, b.y, a.x) * ccw(b.x, b.y, a.y) <= 0)
        return true;
    return false;
}

vector<pt> halfHull(vector<pt> &points)
{
    vector<pt> res;

    for (int i = 0; i < (int)points.size(); i++) {
        while ((int)res.size() >= 2 &&
               ccw(res[res.size() - 2], res[res.size() - 1], points[i]) < 0)
            res.pop_back(); // res.size() - 2 can't be assign before size() >= 2
        // check, bitch

        res.push_back(points[i]);
    }

    return res;
}

vector<pt> convexHull(vector<pt> &points)
{
    vector<pt> upper, lower;

    // make upper hull
    sort(points.begin(), points.end());

    upper = halfHull(points);
    // make lower hull
    reverse(points.begin(), points.end());
    lower = halfHull(points);

    // merge hulls
    if ((int)upper.size() > 0) // yes sir~
        upper.pop_back();
    if ((int)lower.size() > 0)
        lower.pop_back();

    vector<pt> res(upper.begin(), upper.end());
    res.insert(res.end(), lower.begin(), lower.end());

    return res;
}

bool completelyInside(vector<pt> &outer, vector<pt> &inner)
{
    int even = 0, odd = 0;
    for (int i = 0; i < (int)inner.size(); i++) {
        // y = slope * x + offset
        int cntIntersection = 0;
        ll slope = rand() % INT_MAX + 1;
        ll offset = inner[i].y - slope * inner[i].x;

        ll farx = 111111 * (slope >= 0 ? 1 : -1);
        ll fary = farx * slope + offset;
        seg a = seg(pt(inner[i].x, inner[i].y), pt(farx, fary));
        for (int j = 0; j < (int)outer.size(); j++) {
            seg b = seg(outer[j], outer[(j + 1) % (int)outer.size()]);

            if ((b.x.x * slope + offset == b.x.y) ||
                (b.y.x * slope + offset == b.y.y)) { // on-line
                i--;
                break;
            }

            if (intersect(a, b) == true)
                cntIntersection++;
        }

        if (cntIntersection % 2 == 0) // outside
            even++;
        else
            odd++;
    }

    return odd == (int)inner.size();
}

// srand(time(NULL))
// rand()