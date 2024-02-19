#include <bits/stdc++.h> //hard
const int N = 200000+5;
using namespace std;

int fatherRoad[N],fatherRail[N];

int Find(int father[],int x)
{
    if(x!=father[x]) return father[x]=Find(father,father[x]);
    return x;
}
void Union(int father[],int x,int y)
{
    x=Find(father,x);
    y=Find(father,y);
    if(x!=y) father[y]=x;
}
int main() {
    int n,k,l;
    cin>>n>>k>>l;

    for(int i=1;i<=n;i++)
    {
        fatherRoad[i]=i;
        fatherRail[i]=i;
    }
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        Union(fatherRoad,x,y);
    }
    for(int i=1;i<=l;i++)
    {
        int x,y;
        cin>>x>>y;
        Union(fatherRail,x,y);
    }
 
    for(int i=1;i<=n;i++)
    {
        Find(fatherRoad,i);
        Find(fatherRail,i);
    }
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n;i++) mp[make_pair(fatherRoad[i],fatherRail[i])]++;
    for(int i=1;i<=n;i++) cout<<mp[make_pair(fatherRoad[i],fatherRail[i])]<<' ';
    return 0;
}