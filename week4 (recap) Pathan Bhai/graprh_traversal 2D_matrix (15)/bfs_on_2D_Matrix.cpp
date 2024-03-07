// ekta 2D array er source thke baki sob gula cell/set/node er minimum distance tuku ber korar system
#include<iostream>
#include<queue>
#include<vector>
#define pi pair<int, int>
using namespace std;
const int N = 1e3+5;
bool visited[N][N];
int dis[N][N];
int row , col;
vector<pi>path={make_pair(-1,0), make_pair(1,0), make_pair(0,-1), make_pair(0,1)};
bool isValid(int cI, int cJ)
{
    if(cI>=0 && cI<row && cJ>=0 && cJ<col)
    {
        return true;
    }
    else return false;
}
void bfs(int si, int sj)
{
    queue<pi>q;
    q.push(make_pair(si, sj));
    visited[si][sj]=true;
    dis[si][sj]=0;
    while(!q.empty())
    {
        pi f=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int cI = path[i].first+f.first;
            int cJ = path[i].second+f.second;
            if(isValid(cI, cJ) && !visited[cI][cJ])
            {
                q.push(make_pair(cI, cJ));
                dis[cI][cJ] = dis[f.first][f.second] +1;
                visited[cI][cJ] = true;
            }  
        }
    }
}
int main()
{
    cin>>row>>col;
    char matrix[row][col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>matrix[i][j];
        }
    }
    int si, sj;
    cin>>si>>sj;
    bfs(si, sj);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}