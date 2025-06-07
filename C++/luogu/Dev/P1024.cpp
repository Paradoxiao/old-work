#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double fn(double x){
  return a*x*x*x+b*x*x+c*x+d;
}
int main(){
  scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
  double l,r,m,x1,x2;
  int count = 0;
  for(int i=-100;i<100;i++){
    l=i;
    r=i+1;
    x1=fn(l);
    x2=fn(r);
    if(!x1){
      printf("%.2lf ",l);
      count++;
    }
    if(x1*x2<0){
      while(r-l>=0.001){
        m=(l+r)/2;
        if(fn(l)*fn(m)<0)
        r=m;
        else
        l=m;
      }
      printf("%.2lf ",r);
      count++;
    }
    if(count==3)return 0;
  }
  return 0;
}

