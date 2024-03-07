#include<iostream>
using namespace std;
// const int N = 1e3+5;
// int adjM[N][N];
int main()
{
    int V, E;
    cin>>V>>E;
    int adjM[V+1][V+1];
    for(int i=0; i<=V; i++)
    {
        for(int j=0; j<=V; j++)
        {
            adjM[i][j] = 0;
            if(i==j)adjM[i][j] = 1;
        }
    }
    while(E--)
    {
        int s, d;
        cin>>s>>d;
        adjM[s][d] = 1;
        adjM[d][s] = 1;
    }   
    for(int i=0; i<=V; i++)
    {
        for(int j=0; j<=V; j++)
        {
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}