#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int myStrlen(char *s) {
  char *p = s;
  while (*p != '\0') {
    p++;
  }
  return p - s;
}
int myStrcmp(char *s1, char *s2) {
  while (*s1 == *s2) {
    if (*s1 == '\0') {
      return 0;
    }
    s1++;
    s2++;
  }
  return *s1 - *s2;
}
char *myStrcpy(char *source, char *dest) {
  char *temp = dest;
  while (*source != '\0')
    *temp++ = *source++;
  *temp = '\0';
  return dest;
}
int main() {
  char str[100], str2[100];
  gets(str);
  myStrcpy(str, str2);
  printf("%s\n", str2);
}