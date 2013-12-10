#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define WORKTAG 1
int main(int argc,char** argv){

int size,rank;
int i=0;
char a[10000];
double starttime, endtime;


MPI_Status stat;
MPI_Init(&argc,&argv);

MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Status status;

if(rank==0){
	
	MPI_Barrier(MPI_COMM_WORLD);
	starttime = MPI_Wtime();
	MPI_Send(a,1,MPI_CHAR,1,WORKTAG,MPI_COMM_WORLD);
    MPI_Recv(a,1,MPI_CHAR,1,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	endtime   = MPI_Wtime();
	printf("Time for 1 byte is %lf\n",(endtime-starttime)/2);

}
else if (rank==1){

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Recv(a,1,MPI_CHAR,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	MPI_Send(a,1,MPI_CHAR,0,WORKTAG,MPI_COMM_WORLD);
    


}

if(rank==0){
	
	MPI_Barrier(MPI_COMM_WORLD);
	starttime = MPI_Wtime();
	MPI_Send(a,100,MPI_CHAR,1,WORKTAG,MPI_COMM_WORLD);
    MPI_Recv(a,100,MPI_CHAR,1,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	endtime   = MPI_Wtime();
	printf("Time for 100 bytes is %lf\n",(endtime-starttime)/2);

}
else if (rank==1){

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Recv(a,100,MPI_CHAR,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	MPI_Send(a,100,MPI_CHAR,0,WORKTAG,MPI_COMM_WORLD);
    


}



if(rank==0){

	MPI_Barrier(MPI_COMM_WORLD);
	starttime = MPI_Wtime();
	MPI_Send(a,1000,MPI_CHAR,1,WORKTAG,MPI_COMM_WORLD);
    MPI_Recv(a,1000,MPI_CHAR,1,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	endtime   = MPI_Wtime();
	printf("Time for 1000 bytes is %lf\n",(endtime-starttime)/2);

}
else if (rank==1){

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Recv(a,1000,MPI_CHAR,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	MPI_Send(a,1000,MPI_CHAR,0,WORKTAG,MPI_COMM_WORLD);
    


}
if(rank==0){

	MPI_Barrier(MPI_COMM_WORLD);
	starttime = MPI_Wtime();
	MPI_Send(a,10000,MPI_CHAR,1,WORKTAG,MPI_COMM_WORLD);
    MPI_Recv(a,10000,MPI_CHAR,1,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	endtime   = MPI_Wtime();
	printf("Time for 1000 bytes is %lf\n",(endtime-starttime)/2);

}else if (rank==1){

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Recv(a,10000,MPI_CHAR,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	MPI_Send(a,10000,MPI_CHAR,0,WORKTAG,MPI_COMM_WORLD);
    


}






MPI_Finalize();



}


