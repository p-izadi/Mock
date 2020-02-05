#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t > 0){
    t--;
    int n;
    cin >> n;
    int l = 0, r = n;
    int path[n][2] = {{0, 0}};
    for (int i = 0; i < n; i++){
      char d;
      int dx=0, dy=0;
      cin >> d;
      if (d == 'U'){
        dy = 1;
      } else if (d == 'D'){
        dy = -1;
      } else if (d == 'R'){
        dx = 1;
      } else if (d == 'L'){
        dx = -1;
      }
      for (int j = i; j < n; j++){
        path[j][0] += dx;
        path[j][1] += dy;
      }
      for (int j = (i-l+r>0)?i-l+r:0; j < i; j++){
        cout << path[i][0] << " " << path[i][1] << " " << \
        path[j][0] << " " << path[j][1] << endl;
        if (path[j][0] == path[i][0] && path[j][1] == path[i][1]){
          l = j;
          r = i;
        }
      }
    }
    if (r < n){
      cout << l+1 << " " << r+1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
