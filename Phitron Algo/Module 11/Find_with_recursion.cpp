#include <bits/stdc++.h>
using namespace std;
int parent[105];

int find(int tar)
{
    if (parent[tar] == -1)
    {
        return tar;
    }
    int leader = find(parent[tar]);
    return leader;

    // if (parent[tar] != -1)
    // {
    //     find(parent[tar]);
    // }
    // else
    // {
    //     return tar;
    // }
}

int main()
{
    memset(parent, -1, sizeof(parent));
    parent[0] = 1;
    parent[2] = 1;
    parent[3] = 1;
    parent[4] = 5;
    parent[5] = 3;

    cout << find(4) << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << i << " -> " << parent[i] << endl;
    }
    

    return 0;
}