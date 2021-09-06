#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<int>parent(N);
vector<int>s(N);
void make_set(int v)
{
    parent[v] = v;
    s[v] = 1;
}
int find_set(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_set(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(s[a] < s[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        s[a] +=s[b];
    }
}
int main()
{
    for(int i=0;i< N;i++)
    {
        make_set(i);
    }
    int cost = 0;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    for(auto i : edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y)
        {
            continue;
        }
        else
        {
            cost+=w;
            union_set(u,v);
        }
    }
    cout<<cost<<endl;
}
