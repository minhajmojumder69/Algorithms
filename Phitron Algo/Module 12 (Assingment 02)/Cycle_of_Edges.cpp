#include<bits/stdc++.h>
using namespace std;

int parent[100005];
int grp_size[1000005];

int find(int tar)
{
    if (parent[tar] == -1)
    {
        return tar;
    }
    int leader = find(parent[tar]);
    parent[tar] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (grp_size[leader1] >= grp_size[leader2])
    {
        parent[leader2] = leader1;
        grp_size[leader1] += grp_size[leader2];
    }
    else
    {
        parent[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];
    }
} 
int main()
{
    memset(parent, -1, sizeof(parent));
    memset(grp_size, 1, sizeof(grp_size));

    int n,e;
    cin >> n >> e;
    int cycle = 0;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB)
        {
            cycle++;
        }
        else
            dsu_union(a,b);
    }
    cout << cycle << endl;
}