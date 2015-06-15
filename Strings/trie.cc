#include <bits/stdc++.h>
#define MAX 26

using namespace std;

struct Trie
{
  struct Node
  {
    bool isEnded;
    Node * child[MAX];
    Node()
    {
      isEnded=0;
      for(int i = 0 ; i < MAX ; ++i)
	child[i] = nullptr;
    }
  };
  Node *Root;
  Trie()
  {
    Root = new Node();
  }
  bool Insert(string cad)
  {
    Node * tmp = Root;
    for(char c : cad)
      {
	if( !(tmp->child[c-'a']) )
	  tmp->child[c -'a'] = new Node();
	tmp = tmp->child[ c-'a' ];
      }
    tmp->isEnded=1;
  }
  
  bool Find(string cad)
  {
    Node * tmp = Root;
    for(char c : cad)
      {
	if(!(tmp->child[c-'a']) )
	  return 0;
	tmp = tmp->child[c-'a'];
      }
    return tmp->isEnded;
  }
};

int main()
{
  Trie tree;
  string cad;   
  int n; cin >>n;
  for(int i =0 ; i < n ; ++i)
    {
      cin >> cad;
      tree.Insert(cad);
    }
  for(int i = 0 ; i < n *n ; ++i)
    {
      cin >> cad;
      cout << tree.Find(cad) << "\n";
    }
  return 0;
}
