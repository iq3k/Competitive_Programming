int n; // number of nodes

vector<int> adj[MAXN]; // adjacency list of graph

bool visited[MAXN];
int tin[MAXN], low[MAXN];
int timer;
stack <int> st_vex;

vector <pair <int, int>> bridges;
void IS_BRIDGE(int v,int to){
	bridges.push_back({v,to});
}

vector <int> cut_points;
void IS_CUTPOINT(int v){
	cut_points.push_back(v);
}

vector <vector <int>> sccs;
void IS_SCC(int v){
	int u;
	sccs.push_back(vector<int>());
	do {
		u = st_vex.top();
        tin[u] = low[u] = 1e9;
        sccs.back().push_back(u);
        st_vex.pop();
    } while (u != v);
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    st_vex.push(v);
    tin[v] = low[v] = timer++;
    int child=0;
    
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
                
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++child;
        }
    }
    if(p == -1 && child > 1)
        IS_CUTPOINT(v);
    
    if (tin[v] == low[v])
    	IS_SCC(v); 
}

void find() {
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
