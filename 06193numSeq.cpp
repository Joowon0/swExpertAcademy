#include <iostream>
#include <vector>

using namespace std;

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

    // find bounds
    int sameNum = 0;
    for(int i = 0; i < length; i++)
      if (front[i] == back[i]) sameNum++;
    length = length - sameNum;
    
    int upper, lower;
    upper = length - 1;
    lower = length / 2;
    if (length % 2 == 1) lower++;

    
    // cout << lower << " ~ " << upper << endl;

    // end case
    if (lower == upper) {
      cout << "#" << n << " " << upper << endl;
      continue;
    }

    // decrease when a change satisfy two places 
    for (int i = 0; i < front.size(); i++) {
      for (int j = i+1; j < front.size(); j++) {
	// case 1) same for two in sequence - 1 1 2 2
	if (front[i] == front[j] && back[i] == back[j]) {
	  upper--;
	  break;
	}

	// case 2) change within back part - 1 2 2 1
	if (front[i] == back[j] && front[j] == back[i]) {
	  upper--;
	  break;
	}
      }
    }

    // out
    if (upper <= lower) cout << "#" << n << " " << lower << endl;
    else cout << "#" << n << " " << upper << endl;
  }
  
  return 0;
}
