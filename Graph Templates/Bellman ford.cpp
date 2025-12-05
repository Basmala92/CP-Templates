vector<int> dist; // like dijkstra but negative weight
bool bellman(int src, int n, vector<array<int, 3> > edge) {
    int INF = 1e18;
    dist.assign(n, INF);
    dist[0] = 0;
    for (int i = 1; i <= n; i++) {
        bool rex = true;
        for (auto [u,v,w]: edge) {
            if (dist[u] == INF) {
                continue;
            }
            int newd = dist[u] + w;
            if (dist[v] > newd) {
                dist[v] = newd;
                rex = false;
            }
        }
        if (i == n && !rex)return true;
    }

    return false;
}
