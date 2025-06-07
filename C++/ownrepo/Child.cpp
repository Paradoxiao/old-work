#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#define flag 0
int getrand() { return rand() % 9 + 2; }
int main() {
  srand((unsigned int)time(nullptr));
  int a, b, i = 0, aa = 0, bb = 0, ans;
  char ch;
  std::cout
      << "\a想要玩\n\e[31m植物大战僵尸杂交版\e[0m\n你必须先做100道加减法!!!\n";
  while (scanf("%c", &ch) != EOF) {
    if (i == 100) {
      system("start D:/PVZ/pvzHE/pvzHE-Launcher.exe");
      return 0;
    }
    system("clear");
    a = getrand();
    b = getrand();
    ch = rand() % 2;

    // 加法
    if (ch) {
      while ((aa == a && bb == b) || a + b > 10) {
        a = getrand();
        b = getrand();
      }
      printf("\a第%d个:\n请问:%2d +%2d = ? ", ++i, a, b);
      if (flag) {
        printf("\n%4d:", a);
        for (int i = 0; i < a; i++)
          std::cout << "\e[31m *\e[0m";
        std::cout << std::endl;
        printf("%4d:", b);
        for (int i = 0; i < b; i++)
          std::cout << "\e[31m *\e[0m";
        std::cout << std::endl;
        printf("%2d+%d:\e[31m ?\e[0m", a, b);
      }
      scanf("%d", &ans);
      while (ans != a + b) {
        system("clear");
        printf("\e[31m错误\e[0m\n第%d个:\n请问:%2d +%2d = ? ", i, a, b);
        std::cin >> ans;
      }
      // printf("\e[31m答案:%2d +%2d =%2d\e[0m", a, b, a + b);
    }

    // 减法
    else {
      while ((aa == a && bb == b) || a == b || a - b == 1 || b - a == 1) {
        a = getrand();
        b = getrand();
      }
      if (a < b) {
        int temp = b;
        b = a;
        a = temp;
      }
      printf("\a第%d个:\n请问:%2d -%2d = ? ", ++i, a, b);
      if (flag) {
        printf("\n%4d:", a);
        for (int i = 0; i < a; i++)
          std::cout << "\e[31m *\e[0m";
        std::cout << std::endl;
        printf("%4d:", b);
        for (int i = 0; i < b; i++)
          std::cout << "\e[31m *\e[0m";
        std::cout << std::endl;
        printf("%2d-%d:\e[31m ?\e[0m", a, b);
      }
      scanf("%d", &ans);
      while (ans != a - b) {
        system("clear");
        printf("\e[31m错误\e[0m\n第%d个:\n请问:%2d -%2d = ? ", i, a, b);
        std::cin >> ans;
      }
      // printf("\e[31m答案:%2d -%2d =%2d\e[0m", a, b, a - b);
    }
    aa = a;
    bb = b;
  }

  printf("\n本次做题%d个", i);
  return 0;
}