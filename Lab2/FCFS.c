#include<stdio.h>
void findWait(int process[],int n,int bt[],int wt[]){
wt[0]=0;
for(int i=1;i<n;i++){
 wt[i]=bt[i-1]+wt[i-1];
}
}
void findTAT(int process[],int n,int bt[],int tat[],int wt[]){
for(int i=0;i<n;i++){
tat[i]=wt[i]+bt[i];
}
}
void findAVG(int process[],int n,int bt[]){
int wt[n],tat[n];
float total_tat=0;
float total_wt=0;
findWait(process,n,bt,wt);
findTAT(process,n,bt,tat,wt);
printf("\nProcess\tBurst Time\tWaiting Time\tTurnAround Time\n");
for(int i=0;i<n;i++){
total_wt +=wt[i];
total_tat +=tat[i];
printf("%d\t%d\t\t%d\t\t%d\n",process[i],bt[i],wt[i],tat[i]);
}
printf("\nAverage Time=%f",total_wt/n);
printf("\nAverage Turnaround Time=%f\n",total_tat/n);
}
int main(){
int process[]={1,2,3,4};
int n=sizeof process / sizeof process[0];
int burst_time[]={5,6,7,8};
findAVG(process,n,burst_time);
}
