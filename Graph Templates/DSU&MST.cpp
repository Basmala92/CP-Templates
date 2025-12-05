//   DSU
struct DSU {
    DSU(int n) {
        init(n);
    }

    DSU() {
    }

    vector<int> par, sz;

    void init(int n) {
        par.resize(n);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        if (par[u] == u) {
            return u;
        }
        return par[u] = find(par[u]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return false;
        }
        if (sz[u] > sz[v])
            swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};


//    MST (Minimum/Maximum spanning Tree)-> Minumum sort all max sort allr

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3> > edge_list(m);
    for (auto &[w,u,v]: edge_list) {
        cin >> u >> v >> w;
        --u;
        --v;
    }
    sort(all(edge_list));
    DSU dsu(n);
    int ans = 0;
    for (auto &[w,u,v]: edge_list) {
        if (dsu.merge(u, v)) {
            ans += w;
        }
    }
    cout << ans << "\n";
}
