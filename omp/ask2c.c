#include<stdio.h>
#include<omp.h>
#include<stdlib.h>


int main(int argc, char*  argv[]){
int x;
int num_threads=atoi(argv[1]);
int *array=(int*)malloc(300*sizeof(int));
int i;
for(i=0;i<300;i++){
array[i]=0;


}
printf("Threads the user set: %d\n",atoi(argv[1]));

omp_set_num_threads(num_threads);
#pragma omp parallel private(x,i) shared(array)
{
 x = omp_get_thread_num();
 #pragma omp parallel
 for(i=0;i<300;i++){
	#pragma omp atomic
	array[i]++;


}
printf("%d of %d\n",x,num_threads);
}

for(i=0;i<300;i++){
printf("i: %d  %d\n",i,array[i]);


}
return 0;


}
