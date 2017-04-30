algorithm
    ::find: [it s, it t, val] -> it
    ::count: [it s, it t, val] -> int
    ::unique: [it s, it t] -> it (it = new end)
    ::merge: [it s1, it t1, it s2, it t2, it o] -> void (o allocated)

string::
    ::replace(idx, len, string) -> void
    ::find (str, pos = 0) -> idx
    ::substr (pos = 0, len = npos) -> string
string <-> int
    ::stringstream; // remember to clear
    ::sscanf(s.c_str(), "%d", &i);
    ::sprintf(result, "%d", i); string s = result;

math/cstdlib
    ::atan2(y=0, x=-1) -> pi

io printf/scanf
    ::int:                "%d"       /   "%d"
    ::double:             "%lf","f"  /   "%lf"
    ::string:             "%s"       /   "%s"
    ::long long:          "%lld"     /   "%lld"
    ::long double:        "%Lf"      /   "%Lf"
    ::unsigned int:       "%u"       /   "%u"
    ::unsigned long long: "%ull"     /   "%ull"
    ::oct:                "0%o"
    ::hex:                "0x%x"
    ::scientific:         "%e"
    ::width:              "%05d"
    ::precision:          "%.5f"
    ::adjust left:        "%-5d"

io cin/cout
    ::oct:                cout << oct << showbase;
    ::hex:                cout << hex << showbase;
    ::scientific:         cout << scientific;
    ::width:              cout << setw(5);
    ::precision:          cout << fixed << setprecision(5);
    ::adjust left:        cout << setw(5) << left;
