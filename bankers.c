//bankersAlgorithm
#include<stdio.h>
#include<stdlib.h>
int n,res;
void bankers(int need[n][res],int allocation[n][res],int available[res],int flag[n])
{
int count=0,process[n],temp;
int k=0;
while(count < n)
{
for(int i=0;i<n;++i) 
{
int check=0; 
temp = count;
if(flag[i] == 0)
{
for(int j=0;j<res;++j)
{
if(need[i][j] <= available[j])
++check;
}
if(check == res) 
{
flag[i]=1;
for(int j=0;j<res;++j)
available[j] += allocation[i][j];
process[k++] = i+1;
++count;
}
}
}
if(temp==count)
++count;
}
for(int i=0;i<n;++i)
{
if(flag[i]!=1)
{
printf("System is not in safe state\n");
exit(0);
}}
printf("System is in safe state and sequence is \n");
for(int i=0;i<n-1;++i)
{
printf("P%d -> ",process[i]);
}
printf("P%d\n",process[n-1]);
}
int main()
{
printf("Enter the number of processes\n");
scanf("%d",&n);
printf("Enter the number of resources\n");
scanf("%d",&res);
int need[n][res],allocation[n][res],available[res],total[res];
printf("\nEnter the Need Matrix\n");
for(int i=0;i<n;++i)
for(int j=0;j<res;++j)
scanf("%d",&need[i][j]);
printf("\nEnter the Alocation Matrix\n");
for(int i=0;i<n;++i)
for(int j=0;j<res;++j)
scanf("%d",&allocation[i][j]);
printf("\nEnter the available resources\n");
for(int i=0;i<res;++i)
scanf("%d",&available[i]);
int flag[n]; //to mark completed processes
for(int i=0;i<n;++i)
flag[i]=0;
bankers(need,allocation,available,flag);
}
