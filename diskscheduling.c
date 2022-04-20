#include<stdio.h>
#include<stdlib.h>
int head,limit,n;
void fcfs(int arr[n])
{
int seekTime=0,prev=head;
for(int i=0;i<n;++i)
{
int temp = abs(arr[i]-prev);
seekTime += temp;
prev=arr[i];
}
printf("**FCFS**\nseek time is %d\n",seekTime);
}
void sort(int arr[n])
{
for(int i=0;i<n;++i)
{for(int j=i+1;j<n;++j)
{
if(arr[i]>arr[j])
{
int swap = arr[i];
arr[i] = arr[j];
arr[j] = swap;
}}}}
void scan(int arr[n])
{
int seekTime=0,prev=head;
for(int i=0;i<n;++i)
{
if(arr[i]>head)
{
seekTime += abs(arr[i]-prev);
prev=arr[i];
++i;
}}
seekTime += abs(limit-prev);
prev = limit;
for(int i=n-1;i>=0;--i)
{
if(arr[i]<head)
{
seekTime += abs(arr[i]-prev);
prev=arr[i];--i;
}}
printf("**SCAN**\nSeek time %d\n",seekTime);
}
void cScan(int arr[n])
{
int seekTime=0,prev=head;
for(int i=0;i<n;++i)
{
if(arr[i]>head)
{
seekTime += abs(arr[i]-prev);
prev=arr[i];
++i;
}}
seekTime += abs(limit-prev);
seekTime += limit;
prev=0;
for(int i=0;i<n;++i)
{
if(arr[i]<head)
{
seekTime += abs(arr[i]-prev);
prev=arr[i];
++i;
}}
printf("**CSCAN**\nSeektime is %d\n",seekTime);
}
int main()
{
printf("Enter the number of requests\n");
scanf("%d",&n);
int arr[n];
printf("Enter the requests\n");
for(int i=0;i<n;++i)
scanf("%d",&arr[i]);
printf("enter the position of head\n");
scanf("%d",&head);
printf("Enter the limit\n");
scanf("%d",&limit);
fcfs(arr);
sort(arr);
scan(arr);
cScan(arr);
}
