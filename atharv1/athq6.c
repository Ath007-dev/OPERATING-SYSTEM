#include<stdio.h>
#include<stdlib.h>
int main(){
int matrix[3][3]={1,1,1,2,2,2,3,3,3};
int csum1=0;
int csum2=0;
int csum3=0;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
if(j==0){
csum1=csum1+matrix[i][j];
}
if(j==1){
csum2=csum2+matrix[i][j];
}
if(j==2){
csum3=csum3+matrix[i][j];
}

}
}
printf("%d ",csum1);
printf("%d ",csum2);
printf("%d ",csum3);

}
