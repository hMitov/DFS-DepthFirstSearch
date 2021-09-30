#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100

int n, v, used[MAX], i, j;
vector<int>a[MAX];
int G[MAX][2], ribs;
int p[MAX];
vector <int> path_arr;


void spisuk_na_rebra() {
  cout << "Enter the number of V: " << endl;
  cin >> n;
  
	cout << "Enter the number of ribs: ";
	cin >> ribs;

	for (i = 0; i < ribs; i++) {
		for (j = 0; j < 2; j++)
			cin >> G[i][j];
	}
}

void dfs(int k)
{
	cout << k << " ";
	for (i = 0; i < a[k].size(); i++) {
		if (used[a[k][i]])
			continue;
		used[a[k][i]] = 1;
		dfs(a[k][i]);
		p[a[k][i]] = k;
	}
}


void path(int r) {
	if (r != v) {
		path_arr.push_back(r);
		path(p[r]);
	}
}




int main() {
	spisuk_na_rebra();

	cout << "Enter the starting V: ";
	cin >> v;

	for (i = 0; i < ribs; i++) {
		a[G[i][0]].push_back(G[i][1]);
		a[G[i][1]].push_back(G[i][0]);
	}
  
	for (i = 0; i < ribs; i++)
		sort(a[i].begin(), a[i].end());
    
	used[v] = 1;
	dfs(v);
  
  for(i = 1; i <= n; i++) {
     cout << i << " : " << p[i] << endl;
  }
  

	return 0;
}
