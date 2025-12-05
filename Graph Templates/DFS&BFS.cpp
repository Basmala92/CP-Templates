vector<int> euler, in, out, topsort;
vector<vector<int> > adj;
int timer = 0;


//     DFS
void dfs(int u, int p) {
    for (auto v: adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    topsort.push_back(u);
}

//     Euler Tour

void dfs_euler(int u, int p) {
    // subtree of x = range euler[in[x]--->less than out[x]]
    in[u] = ++timer;
    euler.push_back(u);
    for (auto v: adj[u]) {
        if (v == p)continue;
        dfs(v, u);
    }
    out[u] = timer;
}

//    BFS

vector<int> ShortestPath(int src, int des) {
    int n = adj.size();
    vector<int> lvl(n, -1);
    lvl[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (lvl[v] == -1) {
                lvl[v] = lvl[u] + 1;
                q.push(v);
            }
        }
    }
    return lvl;
}

//     0/1 BFS
vector<int> zero_one_BFS(int src, vector<vector<pair<int, int> > > &adj) {
    const long long inf = 1e18;
    const int n = adj.size();
    vector<int> dis(n, inf);
    dis[src] = 0;
    deque<int> dq;
    dq.emplace_back(src);
    while (dq.size()) {
        auto u = dq.front();
        dq.pop_front();
        for (auto [v, w]: adj[u]) {
            long long new_dis = dis[u] + w;
            if (dis[v] <= new_dis)continue;
            if (!w) {
                dq.push_front(v);
            } else {
                dq.push_back(v);
            }
            dis[v] = new_dis;
        }
    }
    return dis;
}
