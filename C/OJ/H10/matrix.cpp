#include <iostream>
#include <vector>

using namespace std;
class matrix {
  int rows, cols;

public:
  vector<vector<int>> Data;
  matrix(int rows, int cols)
      : rows(rows), cols(cols), Data(rows, vector<int>(cols)) {}
  void row_add(int from, int to) {
    if (Data[to][from])
      for (int i = 0; i < cols; i++)
        Data[to][i] ^= Data[from][i];
  }
  void matrix_format() {
    for (int i = 0; i < rows; i++) {
      if (Data[i][i] == 0) {
        int temp = i;
        while (Data[++temp][i] == 0)
          ;
        row_add(temp, i);
      }
      for (int l = 0; l < rows; l++)
        if (l != i && Data[l][i])
          row_add(i, l);
    }
  }
  void matrix_out(int m, int n) {
    for (int i = 0; i < m; i++) {
      for (int l = 0; l < n; l++)
        cout << (l ? " " : "") << Data[i * n + l][cols - 1];
      cout << endl;
    }
  }
};
int delta[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int main() {
  int N;
  cin >> N;
  for (int puzzle = 1; puzzle <= N; puzzle++) {
    int turn[5][6];
    for (int i = 0; i < 5; i++)
      for (int l = 0; l < 6; l++)
        cin >> turn[i][l];
    matrix A(30, 31);
    for (int i = 0; i < 5; i++) {
      for (int l = 0; l < 6; l++) {
        A.Data[6 * i + l][30] = turn[i][l];
        for (int k = 0; k < 5; k++) {
          int x = i + delta[k][0], y = l + delta[k][1];
          if (x >= 0 && x < 5 && y >= 0 && y < 6)
            A.Data[6 * i + l][6 * x + y] = 1;
        }
      }
    }
    A.matrix_format();
    cout << "PUZZLE #" << puzzle << endl;
    A.matrix_out(5, 6);
  }
  return 0;
}