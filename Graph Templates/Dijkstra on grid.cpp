void solve() {
    /*  weighted grid with key/buttons doors and blocked cells
     *  when pressing buttons doors change state find min cost to reach n-1 , m-1
     */
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > grid(n, vector<int>(m));
    vector<vector<bool> > key(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            //-1 Blocked
            // 0 door
        }
    }
    auto in = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != -1;
    };
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        key[x][y] = true;
    }
    int dist[n][m][2];
    memset(dist, INF, sizeof(dist));
    set<array<int, 4> > st;
    st.insert({0, 0, grid[0][0], key[0][0]});
    while (st.size()) {
        auto [x,y,cost,state] = *st.begin();
        if (x == n - 1 && y == m - 1) {
            cout << cost << endl;
            return;
        }
        st.erase(st.begin());
        for (int k = 0; k < 4; k++) {
            int i = x + dx[k], j = y + dy[k];
            if (!in(i, j))continue;
            if (grid[i][j] == 0) {
                //DOOR
                if (!state || dist[i][j][state] <= cost)continue;
                st.erase({i, j, dist[i][j][state], state});
                dist[i][j][state] = cost;
                st.insert({i, j, cost, state});
            } else {
                bool new_state = state ^ (key[i][j]);
                int new_cost = cost + grid[i][j];
                if (dist[i][j][new_state] <= new_cost) continue;
                st.erase({i, j, dist[i][j][new_state], new_state});
                dist[i][j][new_state] = new_cost;
                st.insert({i, j, new_cost, new_state});
            }
        }
    }
    cout << -1 << "\n";
}
