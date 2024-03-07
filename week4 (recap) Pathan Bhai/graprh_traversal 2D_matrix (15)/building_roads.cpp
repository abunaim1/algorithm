#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+7;
vector<int>adjL[N];
bool visited[N];
void dfs(int s)
{
    visited[s] = true;
    for(int x: adjL[s])
    {
        if(visited[x])continue;
        dfs(x);
    }
}
int main()
{
    int v, e;
    cin>>v>>e;
    while(e--)
    {
        int a, b;
        cin>>a>>b;
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }
    vector<int> ans;
    for(int i=1; i<=v; i++)
    {
        if(!visited[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0; i<ans.size()-1; i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}