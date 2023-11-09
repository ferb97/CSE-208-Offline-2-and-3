#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define INF 1000000005


struct Edge
{
    int first;
    int second;
    int weight;
    int index;
};


int n,m,i,j,src,dst;
Edge edges[10005];
vector<pair<int,int> > adj[1005];
int d[1005],parent[1005];
vector<int> path;


void dijkstra()
{
    for(i=0;i<n;i++){
        d[i]=INF;
        parent[i]=-1;
    }

    set<pair<int,int> > q;
    d[src]=0;
    q.insert({0,src});

    while(!q.empty()){
        int t=q.begin()->second;
        q.erase(q.begin());
        for(pair<int,int> p: adj[t]){
            int t1= p.first;
            int w1=p.second;
            if(d[t]+w1<d[t1]){
                q.erase({d[t1],t1});
                d[t1]=d[t]+w1;
                parent[t1]=t;
                q.insert({d[t1],t1});
            }
        }
    }

    int tmp=dst;
    while(tmp!=src){
        path.push_back(tmp);
        tmp=parent[tmp];
    }

    path.push_back(src);
    reverse(path.begin(),path.end());
}


int main()
{
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>edges[i].first>>edges[i].second>>edges[i].weight;
        adj[edges[i].first].push_back({edges[i].second,edges[i].weight});
        //adj[y].push_back({x,weight});
    }
    cin>>src>>dst;

    dijkstra();
    cout<<"Shortest path cost: "<<d[dst]<<endl;
    for(i=0;i<path.size()-1;i++){
        cout<<path[i]<<" -> ";
    }
    cout<<path[i]<<endl;

}
