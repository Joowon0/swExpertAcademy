#include <iostream>
#define timelimit 540;

using namespace std;

int nodeNum, travelDay;
int travelCost[40][40], happy[40], visited[40];
int airportNum, hotelNum[40];
int maxHappy=0, bestRoute[40], cnt = 0;

void dfs(int nodeNow, int timespent, int nthDay, int acqHappy, int route[40], int nthVisit) {
  //  cout << "DAY" << nthDay << " Node " << nodeNow << " acqHappy: " << acqHappy << " time : " << timespent << endl;
  if (timespent > 540) return;
  else if (nodeNow == airportNum && nthDay == travelDay && acqHappy != 0) {
    // check if best
    if (acqHappy > maxHappy) {
      maxHappy = acqHappy;
      for(int i = 0; i < nthVisit; i++)
	bestRoute[i] = route[i];
      cnt = nthVisit;

      // print for test
      // cout << "DAY" << nthDay << " Node " << nodeNow << " acqHappy: " << acqHappy << " time : " << timespent << endl;
      // for(int i = 0; i < nthVisit; i++)
      // 	cout << route[i]+1 << " ";
      // cout << endl;
    }
    return;
  }
  else if (hotelNum[nodeNow]) {
    timespent = 0; nthDay++;
    if (nthDay > travelDay) return;
    visited[nodeNow] = false;
  }

  // int maxHappy = 0;
  for(int i = 0; i < nodeNum; i++) {
    if (visited[i]) continue;
    visited[i] = true; route[nthVisit] = i;
    dfs( i, timespent+travelCost[nodeNow][i], nthDay, acqHappy+happy[i], route, nthVisit+1);
    visited[i] = false;
  }
}

int main() {
  int caseNum;
  cin >> caseNum;

  for(int n = 1; n <= caseNum; n++) {
    maxHappy = 0;
    cin >> nodeNum >> travelDay;

    for(int i = 0; i < nodeNum; i++) {
      hotelNum[i] = 0; visited[i] = 0;
      for(int j = i+1; j < nodeNum; j++) {
	cin >> travelCost[i][j];
	travelCost[j][i] = travelCost[i][j];
      }
    }

    char temp; int temp2;
    for(int i = 0; i < nodeNum; i++) {
      cin >> temp;
      if (temp == 'A') airportNum = i;
      else if (temp== 'P') {
	cin >> temp2 >> happy[i];
	// consider spending time as moving cost
	for (int j = 0; j < nodeNum; j++)
	  travelCost[j][i] += temp2;
      }
      else {
	hotelNum[i] = 1;
	happy[i] = 0;
      }
    }

    int route[40];
    cout << "#" << n << " ";

    dfs(airportNum, 0, 1, 0, route, 0);
    if (maxHappy <= 0) cout << 0 << endl;
    else {
      cout << maxHappy << " ";
      for(int j = 0; j < cnt; j++)
	cout << bestRoute[j]+1 << " ";
      cout << endl;
    }
    maxHappy = 0;
  }
  
  return 0;
}
