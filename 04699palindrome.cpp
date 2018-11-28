#include <iostream>

using namespace std;

int cost[2002];
int memo[2002][2002];
int inStr[2002];

int dfs(int startI, int endI) {
  // end case
  if (startI >= endI) return 0;
  else if (memo[startI][endI] != -1) return memo[startI][endI];
  else if (inStr[startI] == inStr[endI]) return dfs(startI+1, endI-1);

  int sADD1 = dfs(startI+1, endI) + cost[inStr[startI]];
  int eSUB1 = dfs(startI, endI-1) + cost[inStr[endI]];
  int result;

  if (sADD1 < eSUB1) result = sADD1;
  else result = eSUB1;

  memo[startI][endI] = result;
  return result;
}

int main() {
  int caseNum;

  cin >> caseNum;
  for(int n = 1; n <= caseNum; n++) {
    // get input and initialize
    int len, alphaNum;
    cin >> len >> alphaNum;

    char temp;
    for(int i = 0; i < len; i++) {
      cin >> temp;
      inStr[i] = temp - 'a';
      for(int j = i+1; j < len; j++) memo[i][j] = -1;
    }

    int temp1, temp2;
    for(int i = 0; i < alphaNum; i++) {
      cin >> temp1 >> temp2;
      if (temp1 < temp2) cost[i] = temp1;
      else cost[i] = temp2;
    }
    
    
    cout << "#" << n <<  " " << dfs(0, len-1) << endl;
  }
  return 0;
}
