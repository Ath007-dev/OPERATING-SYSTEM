#include<stdio.h>
#include<stdlib.h>
int main(){
int arr[5]={1,2,3,4,5};
int maxi=INT_MIN;
for(int i=0;i<5;i++){
if(maxi<arr[i]){
maxi=arr[i];
}
}
int smax=INT_MIN;
for(int i=0;i<5;i++){
if(smax<arr[i] && arr[i]!=maxi){
smax=arr[i];
}
}
printf("%d",smax);
}
