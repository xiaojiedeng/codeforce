#include <iostream>
#include <map>
using namespace std;

int main() {
  string name;
  int score;
  int maxscore = -1001;
  string winner;
  map<string, int> M;

  int n;
  cin >> n;
  while (n--) {
    cin >> name >> score;
    if (M.find(name) == M.end())
      M[name] = score;
    else
      M[name] += score;

    if (M[name] > maxscore) {
      maxscore = M[name];
      winner = name;
    }
  }

  cout << winner << endl;
  return 0;
} 
