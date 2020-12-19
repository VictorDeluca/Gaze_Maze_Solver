//Efficiency is secondary, if it finishes running by tomorrow it'll still be fine

#include <bits/stdc++.h>
using namespace std;

map<vector<int>,int> visited;
vector<string> mapa; int n,m;

void solve(vector<int> cur, int x, int y){
	vector<int> helper = cur;
	helper.push_back(x); helper.push_back(y);
	if(visited[helper]) return;
	visited[helper] = 1;

	if(mapa[x][y] == 'B') cur[0]++;
	else if(mapa[x][y] == 'b'){
		if(cur[0] > 0) cur[0]--;
		else return;
	}
	else if(mapa[x][y] == 'Y') cur[1]++;
	else if(mapa[x][y] == 'y'){
		if(cur[1] > 0) cur[1]--;
		else return;
	}
	else if(mapa[x][y] == 'M') cur[2]++;
	else if(mapa[x][y] == 'm'){
		if(cur[2] > 0) cur[2]--;
		else return;
	}
	else if(mapa[x][y] == 'G') cur[3]++;
	else if(mapa[x][y] == 'g'){
		if(cur[3] > 0) cur[3]--;
		else return;
	}
	else if(mapa[x][y] == 'P') cur[4]++;
	else if(mapa[x][y] == 'p'){
		if(cur[4] > 0) cur[4]--;
		else return;
	}
	else if(mapa[x][y] == 'C') cur[5]++;
	else if(mapa[x][y] == 'c'){
		if(cur[5] > 0) cur[5]--;
		else return;
	}
	else if(mapa[x][y] == '@') printf("Hello");
	
	if(x+1 < n && mapa[x+1][y]!='-') solve(cur,x+1,y);
	if(x-1 >=0 && mapa[x-1][y]!='-') solve(cur,x-1,y);
	if(y+1 < m && mapa[x][y+1]!='-') solve(cur,y+1,y);
	if(y-1 >=0 && mapa[x][y-1]!='-') solve(cur,y-1,y);
}

int main(){
	int i,j;
	cin >> n >> m; cin.ignore();
	for(i=0;i<n;i++){
		string s; cin >> s;
		mapa.push_back(s);
		cout << mapa[i] << "\n";
	}
	return 0;
}