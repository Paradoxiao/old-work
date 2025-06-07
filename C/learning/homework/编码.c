#include <stdio.h>
void prBit(int num, char *chs) {
  printf("%s: ", chs);
  for (int i = 15; i >= 0; i--) {
    int bit = (num >> i) & 1;
    printf("%d", bit);
  }
  printf("\n");
}
int main() {
  int num;
  scanf("%d", &num);
  prBit(num, "原码");
  // 反码
  int fannum = num;
  if (num < 0) {
    // 负数，先取绝对值，然后按位取反，再设置符号位为1
    fannum = -num;
    for (int i = 0; i < 16; i++) {
      fannum = fannum ^ (1 << i);
    }
    fannum = fannum | (1 << 15);
  }
  prBit(fannum, "反码");
  // 补码
  int bunum = fannum;
  if (num < 0) {
    // 负数，反码加1得到补码
    bunum++;
  }
  // 补码
  prBit(bunum, "补码");
  return 0;
}