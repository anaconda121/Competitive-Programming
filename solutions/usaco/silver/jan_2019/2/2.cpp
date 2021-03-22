// http://www.usaco.org/index.php?page=viewproblem2&cpid=895
/* LOGIC
floodfill ur way through, any # currA ++
anywhere ur floodfill tries to go for a certain component, add that to perim
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 1005
#define MAXM 1005

char grid[MAXN][MAXM]; // the grid itself
int n;
bool visited[MAXN][MAXM]; // keeps track of which nodes have been visited
ll currA = 0;
ll currP = 0;
ll area = 0;
ll perimeter = 0;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void floodfill(int r, int c){
	if(r < 0 || r >= n || c < 0 || c >= n) {
        currP++;
        return; // if outside grid
    }
	if(visited[r][c]) return; // already visited this square
    if (grid[r][c] == '.') {
        currP++;
        return;
    } 
	visited[r][c] = true; // mark current square as visited
	if (grid[r][c] == '#') {
        currA++; 
    }
	// recursively call floodfill for neighboring squares
	floodfill(r, c+1);
	floodfill(r, c-1);
	floodfill(r-1, c);
	floodfill(r+1, c);
}

int main(){
    setIO("perimeter", true);
	cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j] && grid[i][j] == '#'){
				floodfill(i, j);
                if (area == currA) {
                    perimeter = min(perimeter, currP);
                } else if (currA > area) {
                    area = currA;
                    perimeter = currP;
                }
                //cout << currA << " , " << currP << endl; 
                currA = currP = 0;
			}
		}
	}
    cout << area << " " << perimeter << endl;
	return 0;
}