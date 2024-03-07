#include<iostream>
using namespace std;
int main()
{
    int V, E;
    cin>>V>>E;
    vector<pair<int, int> >v;
    while(E--)
    {
        int s, d;
        cin>>s>>d;
        v.push_back(make_pair(s,d));
    }
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}