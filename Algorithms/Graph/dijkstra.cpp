#include <bits/stdc++.h>
using namespace std;

struct comp
{

    bool operator()(pair<int, pair<int, int>> const &a, pair<int, pair<int, int>> const &b)
    {

        return a.first > b.first;
    }
};

int main()
{
    int graph[100][100];
    int n_vertex, n_edge, u, v, w;
    cout << "Enter the number of vertex: ";
    cin >> n_vertex;
    cout << "Enter the number of edge: ";
    cin >> n_edge;

    for (int i = 0; i <= n_vertex; i++)
    {
        for (int j = 0; j <= n_vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter the graph input (u,v,w) " << endl;
    for (int i = 0; i < n_edge; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // for (int i = 1; i <= n_vertex; i++)
    // {
    //     for (int j = 1; j <= n_vertex; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int visited[n_vertex + 10];
    int parent[n_vertex + 10];
    int distance[n_vertex + 10];
    int source;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> queue_edges;
    for (int i = 0; i <= n_vertex; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
        distance[i] = INT_MAX;
    }

    cout << "Enter source: ";
    cin >> source;
    parent[source] = -1;
    distance[source] = 0;
    visited[source] = 1;

    for (int i = 1; i <= n_vertex; i++)
    {
        if (graph[source][i] != 0)
        {
            queue_edges.push(make_pair(distance[source] + graph[source][i], make_pair(source, i)));
        }
    }

    while (!queue_edges.empty())
    {
        w = queue_edges.top().first;
        u = queue_edges.top().second.first;
        v = queue_edges.top().second.second;
        queue_edges.pop();
        if ((visited[v] == 0) && (distance[v] > distance[u] + graph[u][v]))
        {
            parent[v] = u;
            distance[v] = distance[u] + graph[u][v];

            for (int i = 1; i <= n_vertex; i++)
            {
                if (graph[v][i] != 0)
                {
                    queue_edges.push(make_pair(distance[v] + graph[v][i], make_pair(v, i)));
                }
            }
            visited[v] = 1;
        }
    }

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 1; i <= n_vertex; i++)
    {
        if (distance[i] == INT_MAX)
            cout << "Vertex " << i << ": No path" << endl;
        else
            cout << "Vertex " << i << ": " << distance[i] << endl;
    }

    cout << "Enter destination: ";
    int dest;
    cin >> dest;

    if (distance[dest] == INT_MAX)
    {
        cout << "No path from " << source << " to " << dest << endl;
        return 0;
    }

    vector<int> path;
    int current = dest;
    while (current != source)
    {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(source);

    cout << "Shortest path: ";
    for (int i = path.size() - 1; i > 0; i--)
    {
        cout << path[i] << " --> ";
    }
    cout << path[0] << endl;
    cout << "Total distance: " << distance[dest] << endl;

    return 0;
}