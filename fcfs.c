#include<stdio.h>
int main(){
 int n;
 scanf("%d", &n);
int arr[n];
int bt = 0;
for(int i = 0; i<n; i++){
 scanf("%d", &arr[i]);
  bt = arr[i];
  }
int AT = 0;
while(AT>=0 &&  n != '\0'){
int CT = bt - AT;
int tat = CT - AT;
int wt = tat - bt;
}
  for(int i = 0; i< n ; i++){
printf("CT= %d\n", CT );
printf("tat= %d\n", tat );
printf("wt= %d\n", wt );
  }
return 0;
}