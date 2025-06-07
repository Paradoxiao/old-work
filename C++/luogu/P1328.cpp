#include <cstdio>
#include <iostream>
#include <vector>
int show[5][5] = {
    {0, 2, 1, 1, 2},
    {1, 0, 2, 1, 2},
    {2, 1, 0, 2, 1},
    {2, 2, 1, 0, 1},
    {1, 1, 2, 2, 0}
};
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int N, Na, Nb, Ca = 0, Cb = 0;
  cin >> N >> Na >> Nb;
  vector<int> Sa(Na), Sb(Nb);
  for (int &i : Sa)
    cin >> i;
  for (int &i : Sb)
    cin >> i;
  for (int i = 0; i < N; i++) {
    int test = (show[Sa[i % Na]][Sb[i % Nb]]);
    if (!test)
      continue;
    if (test == 1)
      Ca++;
    else
      Cb++;
  }
  cout << Ca << ' ' << Cb;
}