#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define WORKTAG 1
int main(int argc,char** argv){
char hostname[100],a[200];
int size,rank;
int i=0;

MPI_Status stat;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Status status;

if(rank!=0){
    MPI_Recv(a,200,MPI_CHAR,rank-1,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
    printf(" RANK: %d of %d message %s\n",rank,size, a);
}
else{
MPI_Send(argv[argc-1],200,MPI_CHAR,rank+1,WORKTAG,MPI_COMM_WORLD);
printf(" RANK: %d of %d message %s\n",rank,size, argv[argc-1]);
}
//gethostname(hostname,100);

if(rank<(size-1)) {
    
    MPI_Send(a,200,MPI_CHAR,rank+1,WORKTAG,MPI_COMM_WORLD);
}

MPI_Finalize();
}
