#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
  int a, b, w;
  Edge(int a, int b, int w)
  {
    this->a = a;
    this->b = b;
    this->w = w;
  }
};

int n, e;
long long int dis[1005];
vector<Edge> edge_list;
bool cycle = false;

void bellmen_ford()
{
    for (int i = 1; i <= n - 1; i++)
  {
    for (auto ed : edge_list)
    {
      int a, b, w;
      a = ed.a;
      b = ed.b;
      w = ed.w;
      if (dis[a] != LONG_MAX && dis[a] + w < dis[b])
      {
        dis[b] = dis[a] + w;
      }
    }
  }

  for (auto ed : edge_list)
  {
    int a, b, w;
      a = ed.a;
      b = ed.b;
      w = ed.w;
      if (dis[a] != LONG_MAX && dis[a] + w < dis[b])
      {
        cycle = true;
        break;
      }
  }
}

int main()
{
  cin >> n >> e;

  while (e--)
  {
    int a, b, w;
    cin >> a >> b >> w;
    edge_list.push_back(Edge(a, b, w));
  }

  int src,ts;
  cin >> src >> ts;

  for (int i = 1; i <= n; i++)
  {
    dis[i] = LONG_MAX;
  }

  dis[src] = 0;

  while (ts--)
  {
    int tar;
    cin >> tar;

    bellmen_ford();

    if(cycle)
    {
      cout << "Negative Cycle Detected\n";
      break;
    }
    else
      {
        if (dis[tar] == LONG_MAX)
        {
          cout << "Not Possible\n";
        }
        else
        {
          cout << dis[tar] << endl;
        }
        
      }
  }
  

  return 0;
}