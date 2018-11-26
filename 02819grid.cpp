#include <iostream>
#include <set>
#include <string>

using namespace std;

char ins[4][4];
set<string> allNums;

void dfs(int iterNum, string madeSoFar, int X, int Y) {
  // cout << X << ", " << Y << " : " << madeSoFar << endl;
  // end case
  if (iterNum == 7) {
    allNums.insert(madeSoFar);
    return;
  }

  if (X > 0) dfs(iterNum+1, madeSoFar+ins[X-1][Y], X-1, Y);
  if (X < 3) dfs(iterNum+1, madeSoFar+ins[X+1][Y], X+1, Y);
  if (Y > 0) dfs(iterNum+1, madeSoFar+ins[X][Y-1], X, Y-1);
  if (Y < 3) dfs(iterNum+1, madeSoFar+ins[X][Y+1], X, Y+1);
}

int main() {
  int caseNum;

  cin >> caseNum;

  for (int n = 1; n <= caseNum; n++) {
    // inputs
    allNums.clear();
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
	cin >> ins[i][j];

    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
	dfs(0, "", i, j);
    
    //for(set<string>::iterator it=allNums.begin(); it!=allNums.end(); it++)
    //  cout << *it << endl;
    cout << "#" << n << " " << allNums.size() << endl;
  }
  
  return 0;
}
