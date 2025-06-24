#include <bits/stdc++.h>
using namespace std;

int n_vertex;
int n_edge;
int p[100], rankk[100];

void make_set()
{
    for (int i = 0; i < n_vertex; i++)
    {
        p[i] = i;
        rankk[i] = 0;
    }
}

int find_set(int x)
{
    if (p[x] == x)
        return x;
    else
        return p[x] = find_set(p[x]); // Path compression
}

int union_sets(int x, int y)
{
    int r1 = find_set(x);
    int r2 = find_set(y);

    if (r1 == r2)
        return 0; // Already in same set

    if (rankk[r1] > rankk[r2])
        p[r2] = r1;
    else
    {
        p[r1] = r2;
        if (rankk[r1] == rankk[r2]) // Fixed: == instead of =
            rankk[r2]++;
    }
    return 1; // Successful union
}

int main()
{
    n_vertex = 10;
    n_edge = 7;

    make_set();

    union_sets(0, 1);
    union_sets(0, 2);
    union_sets(3, 4);
    union_sets(6, 7);
    union_sets(6, 8);
    union_sets(7, 8);
    union_sets(7, 9);

    cout << find_set(9) << endl; // 7
    cout << find_set(8) << endl; // 7
    cout << find_set(7) << endl; // 7
    cout << find_set(6) << endl; // 7

    cout << find_set(1) << endl; // 1
    cout << find_set(2) << endl; // 1
    cout << find_set(0) << endl; // 1

    cout << find_set(5) << endl; // 5

    cout << find_set(3) << endl; // 4
    cout << find_set(4) << endl; // 4

    return 0;
}