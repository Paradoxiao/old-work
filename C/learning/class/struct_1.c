#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int a, b, c;
  a = 3;
  b = 6;
  c = a << 1;
  printf("%d", c);
  return 0;
}
// typedef struct Student {
//   double b;
//   int a;
//   char c;
//   struct Student *next;
// } STU;
// int main() {
//   printf("%lu", sizeof(STU));
//   return 0;
// }
// typedef struct Student {
//   char *name;
//   int age;
//   double score;
//   struct {
//     int year;
//     int month;
//     int day;
//   } birthday;
// } STU;
// int main() {
//   struct Student zhangsan;
//   STU lisi;
//   lisi.birthday.year = 2000;
//   lisi.name = malloc(30 * sizeof(char));
//   strcpy(lisi.name, "Li Si");
//   lisi.age = 18;
//   lisi.score = 99;
//   zhangsan = lisi;
//   printf("%s %d %lf\n", lisi.name, lisi.age, lisi.score);
//   printf("%s %d %lf\n", zhangsan.name, zhangsan.age, zhangsan.score);
//   strcpy(lisi.name, "Li LiSi");
//   printf("%s %d %lf\n", lisi.name, lisi.age, lisi.score);
// }

// int main() {
//   Student zhangsan;
//   STU lisi;
//   STU stu[30];
//   STU *pStu;
//   lisi.age = 18;

//   zhangsan.age = lisi.age;
//   zhangsan = lisi;
//   scanf("%s%d%lf", lisi.name, &lisi.age, &lisi.score);
//   printf("%s%d%lf\n", lisi.name, lisi.age, lisi.score);

//   strcpy(lisi.name, "Li Si");
//   stu[3].score = 99;
//   pStu = &lisi;
//   (*pStu).age = 20;
//   pStu->age = 20;
//   pStu = malloc(3 * sizeof(STU));
//   free(pStu);
//   return 0;
// }