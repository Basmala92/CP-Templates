vector<vector<int> > SCC, adj;
vector<bool> onstack;
stack<int> st;
vector<int> ids, lolink;
int id;

void dfs(int at) {
    onstack[at] = true;
    ids[at] = lolink[at] = id++;
    st.push(at);
    for (int to: adj[at]) {
        if (ids[to] == -1)dfs(to);
        if (onstack[to]) {
            lolink[at] = min(lolink[at], lolink[to]);
        }
    }

    if (lolink[at] == ids[at]) {
        vector<int> v;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            v.push_back(node);
            lolink[node] = ids[at];
            onstack[node] = false;
            if (node == at) {
                break;
            }
        }
        SCC.push_back(v);
    }
}
