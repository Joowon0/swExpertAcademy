#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> p;

int main() {
  int caseNum;
  cin >> caseNum;

  for(int n = 1; n <= caseNum; n++) {
    int size;
    cin >> size;
    vector<vector<int>> road(size);
    vector<vector<bool>> hadVisited(size);

    char temp;
    for(int i = 0; i < size; i++) {
      road[i].resize(size);
      hadVisited[i].resize(size);
      for(int j = 0; j < size; j++) {
	cin >> temp;
        road[i][j] = temp - '0';
      }
    }

    // initialize check
    // for (int i = 0; i < size; i++) {
    //   for (int j = 0; j < size; j++)
    // 	cout << hadVisited[i][j] << " ";
    //   cout << endl;
    // }

    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push(make_pair(0, make_pair(0,0)));

    while(!pq.empty()) {
      p now = pq.top();
      int nowVal = now.first;
      int nowX = now.second.first;
      int nowY = now.second.second;
      pq.pop();
      // cout << nowX << ", " << nowY << " : " << nowVal << endl;

      // end case
      if (nowX == size-1 && nowY == size-1) {
    	cout << "#" << n << " " << nowVal << endl;
    	break;
      }

      // up
      if (nowX > 0 && !hadVisited[nowX-1][nowY]) {
        pq.push(make_pair(nowVal + road[nowX-1][nowY], make_pair(nowX-1, nowY)));
    	hadVisited[nowX-1][nowY] = true;
      }
      // down
      if (nowX < size-1 && !hadVisited[nowX+1][nowY]) {
        pq.push(make_pair(nowVal + road[nowX+1][nowY], make_pair(nowX+1, nowY)));
    	hadVisited[nowX+1][nowY] = true;
      }
      // left
      if (nowY > 0 && !hadVisited[nowX][nowY-1]) {
        pq.push(make_pair(nowVal + road[nowX][nowY-1], make_pair(nowX, nowY-1)));
    	hadVisited[nowX][nowY-1] = true;
      }
      // right
      if (nowY < size-1 && !hadVisited[nowX][nowY+1]) {
        pq.push(make_pair(nowVal + road[nowX][nowY+1], make_pair(nowX, nowY+1)));
    	hadVisited[nowX][nowY+1] = true;
      }
    }
  }
  
  return 0;
}
