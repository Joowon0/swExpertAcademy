#include <iostream>
#define timelimit 540

using namespace std;

int nodeNum, travelDay;
int travelCost[40][40], happy[40], visited[40];
int airportNum;
int maxHappy=0, bestRoute[40], cnt = 0;

int tourSpot[40], tourNum;
int hotelSpot[40], hotelNum;

int dfs(int nodeNow, int timespent, int nthDay, int acqHappy, int route[40], int nthVisit) {
  //  cout << "DAY" << nthDay << " Node " << nodeNow << " acqHappy: " << acqHappy << " time : " << timespent << endl;

  int visitAny = false;
  // visit tour spot if possible
  for(int t = 0; t < tourNum; t++) {
    int i = tourSpot[t];
    if (visited[i] || timespent+travelCost[nodeNow][i]>timelimit) continue;
    visited[i] = true; route[nthVisit] = i;
    int sucess = dfs( i, timespent+travelCost[nodeNow][i], nthDay, acqHappy+happy[i], route, nthVisit+1);
    if (sucess != -1) visitAny = true;
    visited[i] = false;
  }
  // visit hotel/airport only if there is no time for tour
  if(!visitAny) {
    if (nthDay == travelDay) { // go to airport
      if (timespent+travelCost[nodeNow][airportNum]<=timelimit) {
	route[nthVisit] = airportNum;
	// check if best
	if (acqHappy > maxHappy) {
	  maxHappy = acqHappy;
	  for(int i = 0; i <= nthVisit; i++)
	    bestRoute[i] = route[i];
	  cnt = nthVisit+1;

	  // print for test
	//   cout << "DAY" << nthDay << " Node " << nodeNow << " acqHappy: " << acqHappy << " time : " << timespent << endl;
	//   for(int i = 0; i <= nthVisit; i++)
	//     cout << route[i]+1 << " ";
	//   cout << endl;
	}
	visitAny = true;
      }
    }
    else { // go to hotel
      for(int h = 0; h < hotelNum; h++) {
	int i = hotelSpot[h];
	if (timespent+travelCost[nodeNow][i]>timelimit) continue;
	route[nthVisit] = i;
	int sucess = dfs( i, 0, nthDay+1, acqHappy, route, nthVisit+1);
	if (sucess != -1) visitAny = true;
      }
    }
  }
  if (!visitAny) return -1;
  else return 1;
}

int main() {
  int caseNum;
  cin >> caseNum;

  for(int n = 1; n <= caseNum; n++) {
    maxHappy = tourNum = hotelNum = 0;
    cin >> nodeNum >> travelDay;

    for(int i = 0; i < nodeNum; i++) {
      visited[i] = 0;
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
	tourSpot[tourNum++] = i;
	// consider spending time as moving cost
	for (int j = 0; j < nodeNum; j++)
	  travelCost[j][i] += temp2;
      }
      else {
	hotelSpot[hotelNum++] = i;
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
