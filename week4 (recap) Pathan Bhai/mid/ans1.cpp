#include<iostream>
#include<queue>
#define pi pair<int, int>
using namespace std;
int main()
{
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    int e;
    cin>>e;
    while(e--)
    {
        int a, b;
        cin>>a>>b;
        pq.push(make_pair(a,b));
    }
    while(!pq.empty())
    {
        cout<<pq.top().first <<" " << pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}