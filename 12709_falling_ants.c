#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ANT_DIMENSIONS{
  int l, w, h,v;
}dimensions;

   

int main(){
  char input[20];
  int T;
  int i, max, cursor;
  dimensions ant_table[100];
  int tight_ants[100]; 
  int res;
  
  res=scanf("%d", &T);
  
  while(T != 0){
    for(i=0; i<T; i++){
      res=scanf("%d %d %d", &(ant_table[i].l), &(ant_table[i].w), &(ant_table[i].h));
    }
    
    max=ant_table[0].h;
    cursor=0;
    for(i=0; i<T; i++){
      if(ant_table[i].h > max){
	max = ant_table[i].h;
	cursor=0;
	tight_ants[cursor]=i;
	cursor=1;
      }
      else if (ant_table[i].h == max){
	tight_ants[cursor] = i;
	cursor++;
      }
    }
    
    for(i=0; i<cursor; i++)
      ant_table[tight_ants[i]].v = ant_table[tight_ants[i]].l * ant_table[tight_ants[i]].w * ant_table[tight_ants[i]].h;
    
    if(cursor == 1)
      printf("%d\n", ant_table[tight_ants[0]].v);
    else{
      max=ant_table[tight_ants[0]].v;
      for(i=0; i<cursor; i++)
	if(ant_table[tight_ants[i]].v > max)
	  max = ant_table[tight_ants[i]].v;
      printf("%d\n", max); 
    }
    res=scanf("%d", &T);
  }
      
  return(0);
}
