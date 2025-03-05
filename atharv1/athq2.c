#include<stdio.h>
#include<stdlib.h>
int main(){
int arr[5]={1,2,3,4,5};
int mini=INT_MAX;
for(int i=0;i<5;i++){
if(mini>arr[i]){
mini=arr[i];
}
}
int smin=INT_MAX;
for(int i=0;i<5;i++){
if(smin>arr[i] && arr[i]!=mini){
smin=arr[i];
}
}
printf("%d",smin);
}
