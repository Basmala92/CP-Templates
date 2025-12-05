const int mx_lg = 20;
vector<vector<int> > adj;
vector<vector<int> > dp;
vector<int> depth;
vector<int> par;

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    dp[u][0] = p;
    for (int lg = 1; lg <= mx_lg; lg++) {
        dp[u][lg] = dp[dp[u][lg - 1]][lg - 1];
    }
    for (int v: adj[u]) {
        if (v == p)continue;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for (int lg = mx_lg; lg >= 0; lg--) {
        if (k & (1 << lg)) {
            a = dp[a][lg];
        }
    }
    if (a == b) return a;
    for (int lg = mx_lg; lg >= 0; lg--) {
        if (dp[a][lg] != dp[b][lg]) {
            a = dp[a][lg];
            b = dp[b][lg];
        }
    }
    return dp[a][0];
}

int get_dest(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}
