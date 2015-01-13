#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(){
  int count, i, number, n,dummy,line,a,aux;
  
  dummy=scanf("%d", &n);
  for(line=1; line<=n; line++){
    dummy=scanf("%d %d",&a, &number);
    count=0;
    for(i = 1;i*(i+1)/2<number;++i){
      aux = number-i*(i+1)/2;
      if((aux%(i+1))==0) ++count;
    }
    printf("%d %d\n", a, count);
  }
  
  return 0;
}
  
  
  