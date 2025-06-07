#include <cstdio>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>
class matrix {
private:
  std::vector<std::vector<int>> data;
  int m, n;

public:
  matrix(int row, int col) {
    data.resize(row, std::vector<int>(col, 0));
    m = row;
    n = col;
  }
  matrix(std::vector<std::vector<int>> input) {
    data = input;
    m = input.size();
    n = input[0].size();
  }
  void change(int row, int col, int value) { data[row][col] = value; }
  int get(int row, int col) { return data[row][col]; }
  void output_matrix(void) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        printf(j ? " %5d" : "%5d", data[i][j]);
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  friend std::ostream &operator<<(std::ostream &os, matrix data) {
    for (int i = 0; i < data.m; i++) {
      for (int j = 0; j < data.n; j++)
        os << (j ? " " : "") << std::setw(5) << data.data[i][j];
      // printf(j ? " %5d" : "%5d", data.data[i][j]);
      os << std::endl;
    }
    os << std::endl;
    return os;
  }
  matrix operator+(const matrix other) {
    matrix c(m, n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        c.data[i][j] = data[i][j] + other.data[i][j];
    return c;
  }
  matrix operator-(const matrix other) {
    matrix c(m, n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        c.data[i][j] = data[i][j] - other.data[i][j];
    return c;
  }
  matrix operator*(const matrix other) {
    matrix c(m, other.n);
    if (n != other.m) {
      std::cout << "Error!" << std::endl;
      return c;
    }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          c.data[i][j] += data[i][k] * other.data[k][j];
    return c;
  }
  void add_row(int to, int from, int times) {
    for (int i = 0; i < n; i++)
      data[to][i] += data[from][i] * times;
  }
  matrix eliminate(void) {
    for (int i = 0; i < m; i++) {
      if (data[i][i] == 0) {
        bool all_zero = true;
        for (int j = i + 1; j < m; j++)
          if (data[j][i] != 0) {
            add_row(i, j, 1);
            all_zero = false;
            break;
          }
        if (all_zero)
          continue;
      }
      for (int j = i + 1; j < m; j++) {
        int times = data[j][i] / data[i][i];
        add_row(j, i, -times);
      }
    }
    return *this;
  }
  int det_from_elm(void) {
    if (m != n) {
      std::cout << "Error!" << std::endl;
      return 0;
    }
    int ans = 1;
    for (int i = 0; i < m; i++)
      ans *= data[i][i];
    return ans;
  }
  int det_from_col(void) {
    if (m != n) {
      std::cout << "Error!" << std::endl;
      return 0;
    }
    int ans = 0;
    if (m == 1)
      return data[0][0];
    for (int i = 0; i < m; i++) {
      matrix temp(m - 1, m - 1);
      for (int j = 0; j < m - 1; j++)
        for (int k = 0; k < m - 1; k++)
          temp.data[j][k] = data[j + 1][k < i ? k : k + 1];
      ans += (i % 2 ? -1 : 1) * data[0][i] * temp.det_from_col();
    }
    return ans;
  }
};
int main() {
  matrix a({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  std::cout << a << a.eliminate();
  return 0;
}