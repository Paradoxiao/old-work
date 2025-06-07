#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// 函数用于计算整数和并连接字符串（简单示意，参数规则自行设定）
void custom_operation(int num_args, ...) {
  va_list ap;
  int sum = 0;
  char result_str[100] = ""; // 用于存储连接后的字符串

  va_start(ap, num_args);
  for (int i = 0; i < num_args; i++) {
    if (i % 2 == 0) { // 假设偶数位置是整数参数
      int arg_int = va_arg(ap, int);
      sum += arg_int;
    } else { // 奇数位置是字符串参数
      char *arg_str = va_arg(ap, char *);
      strcat(result_str, arg_str);
    }
  }
  va_end(ap);

  printf("整数求和结果: %d\n", sum);
  printf("连接字符串结果: %s\n", result_str);
}

int main() {
  custom_operation(4, 1, "Hello", 2, " World");
  return 0;
}