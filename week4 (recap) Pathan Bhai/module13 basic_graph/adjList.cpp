#include<iostream>
using namespace std;
const int N = 1e5+7;
vector<int>adjL[N];
int main()
{
    int V, E;
    cin>>V>>E;
    while(E--)
    {
        int s, d;
        cin>>s>>d;
        adjL[s].push_back(d);
        adjL[d].push_back(s);
    }
    for(int i=0; i<=V; i++)
    {
        cout<<"List "<<i<<": ";
        for(int x: adjL[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}