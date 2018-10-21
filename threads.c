#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define BUFFERSIZE 1000
void * MyThreadFunc(void * args);
int sum[10]={0},part=0;
int main(){
	int arr[BUFFERSIZE];
	pthread_t thread[10];
	for(int i=0;i<10;i++){
		pthread_create(&thread[i],NULL,MyThreadFunc,(void*)arr);
	}
	for(int i=0;i<10;i++){
		pthread_join(thread[i],NULL);
	}
	int totalSum=0;
	for(int i=0;i<10;i++)
		totalSum+=sum[i];
	printf("Sum is :%d",totalSum);
  return 0; 
}
 
 void* MyThreadFunc(void * args){
	int *arr=(int*)args;
	int threadPart=part++;
	for(int i=(BUFFERSIZE/10) * threadPart; i< (BUFFERSIZE/10)* (threadPart+1) ; i++){
		arr[i]=i;
		sum[threadPart]+=i;
	}
	printf("present sum is : %d ",sum[threadPart]);
}
