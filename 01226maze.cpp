#include <iostream>

using namespace std;

int maze[16][16];

bool dfs(int x, int y) {
  if (maze[x][y] == 1) return false;
  else if (maze[x][y] == 3) return true;
  else if (maze[x][y] == 0) {
    maze[x][y] = 2;
    int ifGoal = false;

    // up
    if (dfs( x-1, y)) ifGoal = true;
    // down
    if (dfs( x+1, y)) ifGoal = true;
    // left
    if (dfs( x, y-1)) ifGoal = true;
    // right
    if (dfs( x, y+1)) ifGoal = true;

    if (ifGoal) return true;
    else return false;
  }
  else return false;
}

int main() {
  int caseNum = 10;

  while(caseNum--) {
    int n;
    int startX, startY;

    // input
    cin >> n;
    char temp;
    for(int i = 0; i < 16; i++)
      for(int j = 0; j < 16; j++) {
	cin >> temp;
	
	maze[i][j] = temp - '0';
	if (maze[i][j] == 2) {
	  startX = i; startY = j;
	}
      }

    maze[startX][startY] = 0;
    cout << "#" << n << " ";
    if (dfs(startX, startY)) cout << 1 << endl;
    else cout << 0 << endl;
  }
  
  return 0;
}
