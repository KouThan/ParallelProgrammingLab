#include<stdio.h>
#include<omp.h>



int main(int argc, char*  argv[]){
int tid;
int num_threads;
#pragma omp parallel private(tid,num_threads)
{
 tid = omp_get_thread_num();
 num_threads = omp_get_num_threads();
printf("%d of %d\n",tid,num_threads);
}


return 0;


}
