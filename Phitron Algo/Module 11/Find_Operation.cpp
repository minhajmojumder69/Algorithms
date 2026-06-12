#include<bits/stdc++.h>
using namespace std;
int parent[105];

int find(int tar)
{
    while (parent[tar] != -1)
    {
        tar = parent[tar];
    }
    return tar; 
}

int main()
{
    memset(parent,-1,sizeof(parent));
    parent[0] = 1;
    parent[2] = 1;
    parent[3] = 1;
    parent[4] = 5;
    parent[5] = 3;

    cout << find(4) << endl;

  return 0;
}