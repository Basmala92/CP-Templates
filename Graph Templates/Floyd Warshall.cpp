void floyd() {
    // all pairs shortest path
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dist(n, vector<int>(n, INF));
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        dist[u][v] = min(w, dist[u][v]);
        dist[v][u] = min(w, dist[v][u]);
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // if (dist[i][k] < INF && dist[k][j] < INF)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

// umweighted graph how many path between i , j
void cnt_all_paths() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long> > dist(n, vector<long long>(n, 0));
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;

        dist[u][v]++;
        dist[v][u]++;
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] && dist[k][j])
                    dist[i][j] += dist[i][k] * dist[k][j];
            }
        }
    }
}

// check if there is path
void Check_path() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = (dist[i][j] | (dist[i][k] & dist[k][j]));
            }
        }
    }
}
