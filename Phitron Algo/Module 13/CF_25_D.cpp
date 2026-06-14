#include <bits/stdc++.h>
using namespace std;
int parent[1005];
int grp_size[1005];

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

    }
    else
    {
        parent[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        grp_size[i] = 1;
    }
    vector<pair<int,int>> rmv;
    vector<pair<int,int>> create;


    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        int leader1 = find(a);
        int leader2 = find(b);
        if(leader1 == leader2)
            rmv.push_back({a,b});
        else
            dsu_union(a,b);
    }
    for (int i = 2; i <= n; i++)
    {
        int leader1 = find(1);
        int leader2 = find(i);
        if(leader1 != leader2)
            create.push_back({i,1});
            dsu_union(i,1);
    }

    cout << rmv.size() << endl;
    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;
    }

    return 0;
}