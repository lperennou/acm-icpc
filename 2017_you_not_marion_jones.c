#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef TEST
const int test = 1;
#else
const int test = 0;
#endif


int F(int i, int j){
  static int G[10]={1,5,7,6,2,8,3,0,9,4};
  if(i==0)
    return j;
  if(i==1)
    return G[j];
  else
    return F(i-1, G[j]);
}


void to_base_5(char *s, char* num){
  int i, len;
  long long int res;
  /*V represents 4, W represents 3, X represents 2, Y represents 1, and Z represents 0.*/
  res=0;
  len=strlen(s);
  for(0; i<len; i++)
    res+=('Z'-s[i])*pow(10,len-1-i);
  sprintf(num,"%lld",res);
}

void to_base_10(char *base_5, char *base_10){
  int i,len;
  long long int res;
  char tmp[10];
  len=strlen(base_5);
  res=0;
  for(i=0; i<len; i++)
    res += (base_5[i]-'0') * pow(5, len-1-i);
  sprintf(tmp, "%lld", res);
  
  /*padding with zeros and converting asci to integer*/
  len=strlen(tmp);
  for(i=0; i<9-len; i++)
    base_10[i]=0;
  while(i<9){
    base_10[i]=tmp[i-9+len]-'0';
    i++;
  } 
}

long long int to_base_10_int(char* base_10){
  char i;
  long long int res=0;
  for(i=0; i<8; i++)
    res += base_10[i]*pow(10, 7-i);
  return res;
}

char cross(char i, char j){
  if((i<5) && (j<5))
    return (i+j)%5;
  else if((i<5) && (j>=5))
    return ((i+(j-5))%5)+5;
  else if((i>=5) && (j<5)){
    if((i-5-j) >= 0)
      return (((i-5)-j)%5)+5;
    else
      return 5+(i-5-j)+5;
  }
  else{
    if(i>=j)
      return abs((i-j)%5);
    else
      return 5+i-j;
  }
}

char checksum(char* base_10){
  char i, res;
  char num[8];
  
  for(i=0; i<=7; i++)
    num[7-i]=base_10[i];
  if(test)printf("evaluating sequence %lld\n", to_base_10_int(num));
  
  res = cross(F(0, num[0]), F(1, num[1]));
  if(test)printf("F(0, num[0]) = %d x F(1, num[1]) = %d resultat : %d\n", F(0, num[0]), F(1, num[1]), res);
  for(i=2; i<8; i++){
    if(test)printf("res = %d x F(%d, num[%d]) = %d resultat : %d\n", res, i,i,F(i, num[i]), cross(res, F(i, num[i])));
    res=cross(res, F(i, num[i]));
  }
    
    
  return res;
}

void get_type(char *base_10, char *type){
  if(base_10[0] < 2)
    sprintf(type, "%s", "athlete");
  else if(base_10[0] < 4)
    sprintf(type, "%s", "reserve");
  else if(base_10[0] < 6)
    sprintf(type, "%s", "judge");
  else if(base_10[0] < 8)
    sprintf(type, "%s", "staff");
  else 
    sprintf(type, "%s", "press");
}
    
int is_valid(char* base_10){
  if(base_10[0] != 0)
    return 0;
  else 
    return 1;
}
  

int main(){
  char base_5[50], base_10[9], letters[13]; /* max 12 letters input. 5^12-1 makes 9 digits in base 10*/
  char answer[200], type[15], num[2];
  char valid;
  long long int base_10_int;
  char offset;
 
  int n, res, i, j;
  
  res=scanf("%d", &n);
  for(j=0; j<n; j++){
    valid=1;
    offset=sizeof(char);
    res=scanf("%s", letters);
    to_base_5(letters, base_5);
    to_base_10(base_5, base_10);
    
    
    if(is_valid(base_10)==0){ 
      valid = 0;
      offset=0;
      if(test) printf("is_valid said not valid\n");
    }
    else if(checksum(base_10+offset)!=0){ /*don't take first 0 into account*/
      valid = 0;
      if(test) printf("checksum said not valid\n");
    }

    strcpy(answer, letters);
    strcat(answer,"/");
    for(i=offset; i<9; i++){
      sprintf(num,"%d", base_10[i]);
      strcat(answer, num);
    }
    
    if(!valid)
      strcat(answer, " is invalid id number\n");
      
    
    else{
      strcat(answer, " is valid ");
      get_type(base_10+offset, type);
      strcat(answer, type);
      strcat(answer, " id number\n");
    }
    
    printf("%s", answer);
  }
  return 0;
}
  
  