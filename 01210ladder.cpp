#include <iostream>

using namespace std;

int main() {
  int caseNum = 10;

  while(caseNum--) {
    int n;
    cin >> n;

    int ladder[100][100];
    int nowX;
    for(int i = 0; i < 99; i++)
      for(int j = 0; j < 100; j++)
	cin >> ladder[i][j];
    for(int j = 0; j < 100; j++) {
      cin >> ladder[99][j];
      if (ladder[99][j] == 2) nowX = j;
    }

    for (int i = 99; i > 0; i--) {
      // check left up
      if (nowX > 0 && ladder[i-1][nowX-1] == 1) {
	nowX--;
	ladder[i-1][nowX] = -1;
	while(nowX > 0 && ladder[i-1][nowX-1] == 1) {
	  nowX--;
	  ladder[i-1][nowX] = -1;
	}
      }
      // check right up
      else if (nowX < 99 && ladder[i-1][nowX+1] == 1) {
	nowX++;
	ladder[i-1][nowX] = -1;
	while(nowX < 99 && ladder[i-1][nowX+1] == 1) {
	  nowX++;
	  ladder[i-1][nowX] = -1;
	}
      }
      // do nothing for just up

      // cout << "SEQ" << i << endl;
      // for (int i = 0; i < 100; i++) {
      // 	for (int j = 0; j < 100; j++)
      // 	  if (ladder[i][j] == 0) cout << " ";
      // 	  else if (ladder[i][j] == -1) cout << "X";
      // 	  else cout <<"■";
      // 	cout << endl;
      // }
    }

   

    cout << "#" << n << " " << nowX << endl;
  }
  
  return 0;
}
