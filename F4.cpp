#include <iostream>
using namespace std;
long double t = 0;
bool bin(int n, long double first, long double last) {
    long double next;
    bool result = (last > 0);
    for (int i = 2; i < n; i++)
    {
        next = last * 2.0 - first + 2.0;
        if (next < 0)
        {
            result = 0;
            break;
        }
        first = last;
        last = next;
    }
    if (result) t = last;
    return result;
}
int main() {
   // ifstream fin("garland.in");
   // ofstream fout("garland.out");
    int n;
    long double h1;
    cin >> n >> h1;
    long double l = 0, r = h1;
    int i = 0;
    while (i < 100)
    {
        i++;
        long double m = (l + r) / 2;
        if (bin(n, h1, m)) r = m;
        else l = m;
    }
    cout << fixed << t;
    return 0;
}
