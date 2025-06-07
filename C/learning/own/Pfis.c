#include <ncurses.h>

void draw_button(int y, int x, const char *label, int highlighted) {
  if (highlighted) {
    attron(A_REVERSE); // 高亮
  }
  mvprintw(y, x, "[ %s ]", label);
  if (highlighted) {
    attroff(A_REVERSE);
  }
}

int main() {
  initscr();            // 初始化屏幕
  noecho();             // 禁止输入回显
  cbreak();             // 禁止行缓冲
  keypad(stdscr, TRUE); // 启用键盘支持

  int ch;
  int selected = 0;

  while (1) {
    clear();
    draw_button(5, 10, "OK", selected == 0);
    draw_button(7, 10, "Cancel", selected == 1);
    refresh();

    ch = getch();
    switch (ch) {
    case KEY_UP:
      selected = (selected - 1 + 2) % 2;
      break;
    case KEY_DOWN:
      selected = (selected + 1) % 2;
      break;
    case '\n': // 回车键
      if (selected == 0) {
        mvprintw(10, 10, "OK pressed!");
      } else {
        mvprintw(10, 10, "Cancel pressed!");
      }
      refresh();
      getch();
      endwin();
      return 0;
    }
  }
}
