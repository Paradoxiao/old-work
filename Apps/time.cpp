#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

struct my_time {
private:
  time_t now;

public:
  int h, m, s;
  void get_time(void);
  void put_time(void);
  void print_time(int, int);
};

int main(int args, char *agr[]) {
  srand((unsigned int)time(nullptr));
  my_time a;
  int Color;
  while (true) {
    system("clear");
    int color = 41 + rand() % 7;
    while (Color == color)
      color = 41 + rand() % 7;
    a.print_time(atoi(agr[1]), color);
    sleep(1);
    Color = color;
  }
  return 0;
}

void my_time::get_time(void) {
  time_t now = time(0);
  char *str_time = ctime(&now);
  h = (str_time[11] - '0') * 10 + str_time[12] - '0';
  m = (str_time[14] - '0') * 10 + str_time[15] - '0';
  s = (str_time[17] - '0') * 10 + str_time[18] - '0';
}

void my_time::put_time(void) {
  get_time();
  std::printf("%02d:%02d:%02d\n", h, m, s);
}

void my_time::print_time(int n, int color) {
  char num[10];
  get_time();
  std::sprintf(num, "%02d%02d%02d", h, m, s);
  int bit;
  std::printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  // 行
  for (bit = 0; bit < 6; bit++) {
    if (bit)
      std::printf("  ");
    std::printf("  ");
    for (int i = 0; i < n; i++)
      std::printf(num[bit] == '2' || num[bit] == '3' || num[bit] == '5' ||
                          num[bit] == '6' || num[bit] == '7' ||
                          num[bit] == '8' || num[bit] == '9' || num[bit] == '0'
                      ? "\e[%dm  \e[0m"
                      : "  ",
                  color);
    std::printf("  ");
  }
  std::printf("\n");

  // 列
  for (int i = 0; i < n; i++) {
    for (bit = 0; bit < 6; bit++) {
      if (bit)
        std::printf("  ");
      std::printf(num[bit] == '4' || num[bit] == '5' || num[bit] == '6' ||
                          num[bit] == '8' || num[bit] == '9' || num[bit] == '0'
                      ? "\e[%dm  \e[0m"
                      : "  ",
                  color);
      for (int i = 0; i < n; i++)
        std::printf("  ");
      std::printf(num[bit] == '1' || num[bit] == '2' || num[bit] == '3' ||
                          num[bit] == '4' || num[bit] == '7' ||
                          num[bit] == '8' || num[bit] == '9' || num[bit] == '0'
                      ? "\e[%dm  \e[0m"
                      : "  ",
                  color);
    }
    std::printf("\n");
  }

  // 行
  for (bit = 0; bit < 6; bit++) {
    if (bit)
      std::printf("  ");
    std::printf("  ");
    for (int i = 0; i < n; i++)
      std::printf(num[bit] == '2' || num[bit] == '3' || num[bit] == '5' ||
                          num[bit] == '6' || num[bit] == '8' ||
                          num[bit] == '9' || num[bit] == '4'
                      ? "\e[%dm  \e[0m"
                      : "  ",
                  color);
    std::printf("  ");
  }
  std::printf("\n");

  // 列
  for (int i = 0; i < n; i++) {
    for (bit = 0; bit < 6; bit++) {
      if (bit)
        std::printf("  ");
      std::printf(num[bit] == '2' || num[bit] == '6' || num[bit] == '8' ||
                          num[bit] == '0'
                      ? "\e[%dm  \e[0m"
                      : "  ",
                  color);
      for (int i = 0; i < n; i++)
        std::printf("  ");
      std::printf(num[bit] == '1' || num[bit] == '5' || num[bit] == '3' ||
                          num[bit] == '4' || num[bit] == '7' ||
                          num[bit] == '8' || num[bit] == '9' ||
                          num[bit] == '0' || num[bit] == '6'
                      ? "\e[%dm  \e[0m"
                      : "  ",
                  color);
    }
    std::printf("\n");
  }

  // 行
  for (bit = 0; bit < 6; bit++) {
    if (bit)
      std::printf("  ");
    std::printf("  ");
    for (int i = 0; i < n; i++)
      std::printf(num[bit] == '2' || num[bit] == '3' || num[bit] == '5' ||
                          num[bit] == '6' || num[bit] == '8' ||
                          num[bit] == '9' || num[bit] == '0'
                      ? "\e[%dm  \e[0m"
                      : "  ",
                  color);
    std::printf("  ");
  }
  std::printf("\n");

  std::printf("\n");
  std::printf("\n\n\n\n\n\n\n\n\n\n\n");
}
