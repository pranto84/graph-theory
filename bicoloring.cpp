#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
vector <int > edge[1000];

bool bicoloring(int snode, int node)
{
    queue<int>q;
    int colour[node] = {0};
    q.push(snode);
    colour[snode] = 1;
    while(!q.empty()){
        int a = q.front();
        int b = edge[a].size();
        for(int i = 0; i<b; i++){
            if(colour[edge[a][i]] == 0){
                if(colour[a] == 1)
                    colour[edge[a][i]] = 2;
                else if(colour[a] == 2)
                    colour[edge[a][i]] = 1;
                q.push(edge[a][i]);
            }
            else if(colour[edge[a][i]] == 1){
                if(colour[a] == 1)
                    return false;
                else if(colour[a] == 2)
                    continue;
            }
            else if(colour[edge[a][i]] == 2){
                if(colour[a] == 2)
                    return false;
                else if(colour[a] == 1)
                    continue;
            }
        }
        q.pop();
    }
    return true;
}
int main()
{
    int n, l;
    cin >> n >> l;
    if(n==0)
        return 0;
    while(l--){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    bool temp = bicoloring(0, n);
    if(temp)
        cout << "BICOLORABLE." << endl;
    else
        cout << "NOT BICOLORABLE." << endl;
    for(int i = 0; i<n; i++){
        edge[i].clear();
    }
    return 0;
}
