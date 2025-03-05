#include<stdio.h>
#include<stdlib.h>
int main(){
int matrix[3][3]={1,1,1,2,2,2,3,3,3};
int sum=0;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
if(i==j){
sum=sum+matrix[i][j];
}
}
}
printf("%d",sum);
}
