#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#ifdef TEST
const int test = 1;
#else
const int test = 0;
#endif

long next(long i){
  if((i%2)==0)
    return i/2;
  else
    return 3*i+1;
}

long min(long a, long b){
  if(a<=b)
    return a;
  else
    return b;
}

long max(long a, long b){
  if(a>=b)
    return a;
  else
    return b;
}

long cycle(long a){
  if(a==1)
    return 1;
  else
    return 1+cycle(next(a));
}
  

int main(){
  long i,j,res,maximum,c;
  while((res=scanf("%ld %ld",&i, &j)) > 0){
    maximum=0;
    for(res=min(i,j); res<=max(i,j); res++){
      if(maximum < (c=cycle(res)))
	maximum=c;
    }
    printf("%ld %ld %ld\n", i,j,maximum);
  }
  return 0;
}
	
      
    