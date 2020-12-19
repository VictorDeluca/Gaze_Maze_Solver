//Efficiency is secondary, if it finishes running by tomorrow it'll still be fine

#include <bits/stdc++.h>
using namespace std;

map<pair<vector<int>,vector<string>>,int> visited; int n,m;

void solve(vector<string> mapa, vector<int> cur, int x, int y, vector<int> ans){
	vector<int> helper = cur;
	helper.push_back(x); helper.push_back(y);
	if(visited[make_pair(helper,mapa)]) return;
	visited[make_pair(helper,mapa)] = 1;

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
	else if(mapa[x][y] == '@'){
		int i;
		for(i=0;i<ans.size();i+=2)
			printf("%d %d\n",ans[i],ans[i+1]);
		
		exit(0);
	}
	if(mapa[x][y] != '*'){ ans.push_back(x); ans.push_back(y); }
	mapa[x][y] = '*';
	if(x+1 < n && mapa[x+1][y]!='-') solve(mapa,cur,x+1,y,ans);
	if(x-1 >=0 && mapa[x-1][y]!='-') solve(mapa,cur,x-1,y,ans);
	if(y+1 < m && mapa[x][y+1]!='-') solve(mapa,cur,x,y+1,ans);
	if(y-1 >=0 && mapa[x][y-1]!='-') solve(mapa,cur,x,y-1,ans);
}

int main(){
	int i,j; vector<string> mapa;
	cin >> n >> m; cin.ignore();
	for(i=0;i<n;i++){
		string s; cin >> s;
		mapa.push_back(s);
	}
	vector<int> empty; vector<int> zero;
	for(i=0;i<6;i++) zero.push_back(0);
	//Each call to the 'solve' function must be done in the form "solve(mapa,zero,x,y,empty)", where x and y are the player's starting coordinates
	solve(mapa,zero,16,21,empty);

	return 0;
}