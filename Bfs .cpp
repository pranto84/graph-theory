#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAX 10000
int visit[MAX] = {0};
int path[MAX];

vector <int> edge[MAX];

void bfs(int source)
{
    queue <int> q;
    visit[source] = 1;
    path[source] = 0;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        int length = edge[u].size();
        for(int i=0; i<length; i++){
            if(visit[edge[u][i]] == 0){
                visit[edge[u][i]] = 1;
                q.push(edge[u][i]);
                path[edge[u][i]] = path[u]+1;
            }
        }
        q.pop();
    }
}
int main()
{
    cout << "How many node?"<< endl;
    int node, line;
    cin >> node;
    cout << "How many edge?" << endl;
    cin >> line;
    for(int i=1; i<=line ; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    int source;
    cout << "Enter the source:";
    cin >> source;
    bfs(source);
    for(int i = 1; i<= node; i++){
        cout << source<<" to distance " << i << " is " << path[i] << endl;
    }

    return 0;
}
