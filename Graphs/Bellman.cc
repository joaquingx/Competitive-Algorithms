#include <bits/stdc++.h>
using namespace std;

/*
  SSP Algorithm in O(n^2), it allows negative weights
  Relax all vertices n-1 times, because the SSP is a 
  Simple Path, after the n-1 tmes we obtain the min dist(source,v)
  for all v that is in V.
  Bellman's Ford Algorithm:
  bellman(v): v is the source vertex, in d[] we have the dist of all
  vertices with respect source.
*/


struct edge 
{
  int from,to, cost;
};

int n, m;
vector<edge> e; // Edge List 
const int INF = 1000000000;

void bellman(int v) 
{
  vector<int> d (n, INF);
  d[v] = 0;
  for (int i = 0 ; i < n-1 ; ++i)
    for (int j=0; j < m; ++j)
      if (d[e[j].from] < INF)
	d[e[j].to] = min (d[e[j].to], d[e[j].from] + e[j].cost);
  
  for(int i = 0 ; i < n; ++i)
    {
      cout << "Vertex " << i+1 << ": " << d[i] << "\n";
    }
}



int main()
{
  cin >> n >> m ;
  e.resize(m);
  for(int i = 0 ; i < m ; ++i)
    {
      cin >> e[i].from >> e[i].to  >> e[i].cost;
      --e[i].from; --e[i].to; // 0-Index
    }
  bellman(0);
  return 0;
}
