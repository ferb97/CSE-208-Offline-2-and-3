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


int n,m,i,j,k;
Edge edges[10005];
vector<pair<int,int> > adj[105];
int d[105][105];


bool floyd_warshall()
{

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            d[i][j]=INF;
        }
    }

    for(i=1;i<=n;i++){
        d[i][i]=0;
    }

    for(i=1;i<=n;i++){
        for(j=0;j<adj[i].size();j++){
            d[i][adj[i][j].first]=adj[i][j].second;
        }
    }

    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(d[i][k]<INF&&d[k][j]<INF)
                  d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    bool flag=false;
    for(i=1;i<=n;i++){
        if(d[i][i]<0){
           flag=true;
           break;
        }
    }

    return flag;
}


int main()
{
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>edges[i].first>>edges[i].second>>edges[i].weight;
        adj[edges[i].first].push_back({edges[i].second,edges[i].weight});
        //adj[y].push_back({x,weight});
    }

    bool flag=floyd_warshall();
    if(flag){
       cout<<"The graph contains a negative cycle"<<endl;
       return 0;
    }

    cout<<"Shortest distance matrix:"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){

            if(d[i][j]==INF){
               cout<<"INF ";
               continue;
            }

            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}
