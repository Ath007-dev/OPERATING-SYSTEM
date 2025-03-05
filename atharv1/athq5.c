#include<stdio.h>
#include<stdlib.h>
int main(){
int matrix[3][3]={1,1,1,2,2,2,3,3,3};
int sum1=0;
int sum2=0;
int sum3=0;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
if(i==0){
sum1=sum1+matrix[i][j];
}
if(i==1){
sum2=sum2+matrix[i][j];
}
if(i==2){
sum3=sum3+matrix[i][j];
}

}
}
printf("%d ",sum1);
printf("%d ",sum2);
printf("%d ",sum3);

}
