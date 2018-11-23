#include <iostream>
#include <vector>

using namespace std;

// change if possible to satisfy two places
bool canTwoPlace(vector<int> &front, vector<int> &back, int sameI) {
  for(int i = sameI; i < front.size(); i++) {
    for(int j = i+1; j < front.size(); j++) {
      // case 1) same for two in sequence
      // 1 1 2 2
      if (front[i] == front[j] && back[i] == back[j]) {
	front[j] = back[j];
	back[i] = front[i];
	return true;
      }

      // case 2) change within back part
      // 1 2 2 1
      if (front[i] == back[j] && front[j] == back[i]) {
	back[i] = front[i];
	back[j] = front[j];
	return true;
      }
    }
  }
  return false;
}

int main() {
  int Num;
  cin >> Num;

  for(int n = 1; n <= Num; n++) {
    // Get inputs
    int length;
    cin >> length;

    vector<int> front(length), back(length);
    for(int i = 0; i < length; i++)
      cin >> front[i];
    for(int i = 0; i < length; i++)
      cin >> back[i];

    int cnt = 0, sameIndex = 0;
    while(cnt < 10) {
      // stop when the two is the same
      while(front[sameIndex] == back[sameIndex] && sameIndex < length) sameIndex++;
      
      if (sameIndex >= length) {
	cout << "#" << n << " " << cnt << endl;
	break;
      }

      // check if a change can satisfy two places
      if (!canTwoPlace(front, back, sameIndex)) {
	// change that satisfy one place

	// seq 1) find first not-match index
	int x = sameIndex;
	
	// seq 2) find index of first[x] - at front vector
	bool ifChanged = false;
	for(int y = sameIndex+1; y < length; y++) {
	  if (front[x] == front[y]){
	    // swap
	    front[y] = back[x];
	    back[x] = front[x];
	    ifChanged = true;
	    break;
	  }
	}

	if(!ifChanged) {
	  // seq 2) find index of first[x] - at back vector
	  for(int y = sameIndex+1; y < length; y++) {
	    if (front[x] == back[y]) {
	      // swap
	      back[y] = back[x];
	      back[x] = front[x];
	      break;
	    }
	  }
	}
      }

      cnt++;


      // Print for test
      // cout << cnt << " : ";
      // for(int i = 0; i < length; i++)
      // 	cout << front[i] << " ";
      // cout << "\t";
      // for(int i = 0; i < length; i++)
      // 	cout << back[i] << " ";
      // cout << endl;
    }
  }
  
  return 0;
}
