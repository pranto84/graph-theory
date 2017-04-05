#include <bits/stdc++.h>

using namespace std;
#define MAX 100000
struct edge{
    int u, v;
};
bool comp(pair<int,edge>p, pair<int,edge>q){
    return p.first<q.first;
}

vector<pair<int, edge> > e;
vector<pair<int, edge> > result;
int visit[MAX];

int find_r(int r)
{
	if(visit[r] == r)
        return r;
    else
        return visit[r]=find_r(visit[r]);
}

int MST(int n)
{
    int cnt = 0, cost=0;
    for(int i=0; i <= n; i++)
        visit[i] = i;

    for(int i = 0; i<e.size(); i++){
        int u = find_r(e[i].second.u);
        int v = find_r(e[i].second.v);
        if(u != v){
            visit[u] = v;
            cnt++;
            cost += e[i].first;
            result.push_back(e[i]);
        }
        if(cnt == n-1)
            break;
    }
    return cost;
}

int main()
{
    int node, line;
    pair<int , edge> p;

    edge ob;
    int cost;
    cin >> node >> line;


    for(int i= 0; i<line; i++){
        int u, v;
        cin >> u >> v >> cost;
        ob.u = u;
        ob.v = v;
        p.first = cost;
        p.second = ob;
        e.push_back(p);
    }
    sort(e.begin(), e.end(), comp);
    cost = MST(node);
    // total cost of spaning tree//
    cout << cost << endl;
    //which node are connected and what is the cost //
    for(int i=0; i<= result.size(); i++){
        cout << result[i].second.u << " " << result[i].second.v ;
        cout <<" " << result[i].first << endl;
    }
    return 0;
}
