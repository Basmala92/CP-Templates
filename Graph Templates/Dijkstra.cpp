//  Using Priority Queue
vector<ll> dijkstra_nlogn(int src, vector<vector<pair<int, int> > > &adj) {
    /// O( V * log(V) + E)
    const ll inf = 1e18;
    const int n = adj.size();
    vector<ll> dis(n, inf);
    dis[src] = 0;
    priority_queue<pair<ll, int> > pq;
    pq.emplace(0, src);
    while (pq.size()) {
        auto [d, u] = pq.top();
        d *= -1;
        pq.pop();
        if (dis[u] < d) continue;
        for (auto [v, w]: adj[u]) {
            ll new_dis = dis[u] + w;
            if (dis[v] > new_dis) {
                dis[v] = new_dis;
                pq.emplace(-dis[v], v);
            }
        }
    }
    return dis;
}

// NOTE const factor of Priority queue better than set

//     Using Set
vector<ll> dijkstra_nlogn_set(int src, vector<vector<pair<int, int> > > &adj) {
    const ll inf = 1e18;
    const int n = adj.size();
    vector<ll> dis(n, inf);
    dis[src] = 0;
    set<pair<ll, int> > st;
    st.emplace(0, src);
    while (st.size()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        for (auto [v, w]: adj[u]) {
            ll new_dis = dis[u] + w;
            if (dis[v] > new_dis) {
                st.erase({dis[v], v});
                dis[v] = new_dis;
                st.emplace(dis[v], v);
            }
        }
    }
    return dis;
}
