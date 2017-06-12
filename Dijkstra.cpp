#include <bits/stdc++.h>

using namespace std;
#define MAX 100000

int dijkstra(vector<int> e[], vector<int>c[], int source, int endp)
{
    pair < int , int> p , q;
    priority_queue <pair <long long , int>, vector<pair<long long, int> > , greater<pair<long long, int> >  > pq;
    int dis[MAX];
    for(int i = 0; i<MAX; i++)
        dis[i] = 9999999;
    dis[source] = 0;
    p.first = 0;
    p.second = source;
    pq.push(p);
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        int cost = dis[p.second];
        for(int i=0; i<e[p.second].size(); i++){
            q.first = c[p.second][i] + cost;
            q.second = e[p.second][i];
            if(dis[q.second] > q.first){
                dis[q.second] = q.first;
                pq.push(q);
            }
        }
    }
    return dis[endp];
}

int main()
{
    cout << "Enter how many node and how many edge: " << endl;
    int node, line;
    cin >> node >> line;
    vector<int > e[node];
    vector<int> cost[node];
    for(int i=0; i < line; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(v);
        e[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int source,end_p;
    cout <<" Enter the source position and end position" << endl;
    cin >> source >> end_p;
    int distance = dijkstra(e, cost, source, end_p);  // here 0 is source;
    cout << distance << endl;
    return 0;
}
/* better see the Codeforces 20C.cpp  */
