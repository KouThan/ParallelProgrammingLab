#include<stdio.h>
#include<omp.h>



int main(int argc, char*  argv[]){
int tid;
int num_threads=atoi(argv[1]);
omp_set_num_threads(num_threads);
#pragma omp parallel private(tid)
{
 
 tid = omp_get_thread_num();
 
printf("%d of %d\n",tid,num_threads);
}


return 0;


}
