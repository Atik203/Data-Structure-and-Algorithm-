#include <bits/stdc++.h>
using namespace std;

int rankk[100], p[100];
int n_vertex;

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
        return p[x] = find_set(p[x]);
}

bool union_sets(int x, int y)
{
    int r1 = find_set(x);
    int r2 = find_set(y);

    if (r1 == r2)
        return false;
    if (rankk[r1] > rankk[r2])
    {
        p[r2] = r1;
    }
    else
    {
        p[r1] = r2;
        if (rankk[r1] == rankk[r2])
        {
            rankk[r2]++;
        }
    }
    return true;
}

void findConnectedComponents()
{
    map<int, vector<int>> components;

    for (int i = 0; i < n_vertex; i++)
    {
        int root = find_set(i);
        components[root].push_back(i);
    }

    cout << "Number of connected components: " << components.size() << endl;
    cout << "Connected Components: " << endl;

    int component_num = 1;
    for (auto component : components)
    {
        cout << "Component " << component_num << ": ";
        for (int i = 0; i < component.second.size(); i++)
        {
            cout << component.second[i];
            if (i < component.second.size() - 1)
                cout << " -> ";
        }

        cout << endl;
        component_num++;
    }
}

int main()
{
    int n_edges;
    cout << "Enter num of vertex: ";
    cin >> n_vertex;
    cout << "Enter num of edges: ";
    cin >> n_edges;

    make_set();

    cout << "Enter Edges u v" << endl;
    for (int i = 0; i < n_edges; i++)
    {
        int u, v;
        cout << "Edge: " << i + 1 << ": ";
        cin >> u >> v;
        union_sets(u, v);
    }
    findConnectedComponents();

    return 0;
}