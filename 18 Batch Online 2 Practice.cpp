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
    double weight;
    int index;
};


int n,m,i,j,src,dst;
Edge edges[10005];
vector<pair<int,double> > adj[1005];
int parent[1005];
double d[1005];
vector<int> path;


bool bellman_ford()
{
    for(i=0;i<n;i++){
        d[i]=-1000000005;
        parent[i]=-1;
    }

    bool flag=false;
    d[src]=1.0;

    for(i=0;i<n;i++){
        flag=false;
        for(j=0;j<m;j++){
            if(d[edges[j].second]<d[edges[j].first]*edges[j].weight){
                d[edges[j].second]=d[edges[j].first]*edges[j].weight;
                parent[edges[j].second]=edges[j].first;
                flag=true;
            }
        }
    }

    if(flag){
       return true;
    }

    int tmp=dst;
    while(tmp!=src){
        path.push_back(tmp);
        tmp=parent[tmp];
    }

    path.push_back(src);
    reverse(path.begin(),path.end());

    return false;
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

    bool flag=bellman_ford();

    if(flag){
       cout<<"The graph contains a negative cycle"<<endl;
       return 0;
    }

    cout<<"The graph does not contain a negative cycle"<<endl;
    cout<<"Shortest path cost: "<<d[dst]<<endl;
    for(i=0;i<path.size()-1;i++){
        cout<<path[i]<<" -> ";
    }
    cout<<path[i]<<endl;

}

