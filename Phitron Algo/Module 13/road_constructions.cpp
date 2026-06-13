#include <bits/stdc++.h>
using namespace std;
int parent[100005];
int grp_size[100005];
int cmp, mx;

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

    if (leader1 == leader2)
        return;

    if (grp_size[leader1] >= grp_size[leader2])
    {
        parent[leader2] = leader1;
        grp_size[leader1] += grp_size[leader2];

        mx = max(grp_size[leader1], mx);
    }
    else
    {
        parent[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];

        mx = max(grp_size[leader2], mx);
    }
    cmp--;
}

int main()
{
    int n, e;
    cin >> n >> e;
    cmp = n;
    mx = 1;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        grp_size[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << mx << endl;
    }

    return 0;
}