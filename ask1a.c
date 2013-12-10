#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<string.h>
#define WORKTAG 1
int main(int argc,char** argv){
char hostname[100],a[1000];
int size,rank,position=0;
int i=0;
char fnameF[20];
char lnameF[20];
int ageF;
char AMF[10] ;


char fname[20];
char lname[20];
int age;
char AM[10];

strcpy(fname,"Athanasios");
strcpy(lname,"Kountouras");
strcpy(AM,"21018");
age=21;

MPI_Status stat;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Status status;

if(rank!=0){
    
    MPI_Recv(a,1000,MPI_CHAR,rank-1,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
    printf(" RANK: %d of %d\n",rank,size);
}
else{
    MPI_Pack(fname,20,MPI_CHAR,a,1000,&position,MPI_COMM_WORLD);
    MPI_Pack(lname,20,MPI_CHAR,a,1000,&position,MPI_COMM_WORLD);
    MPI_Pack(&age,1,MPI_INT,a,1000,&position,MPI_COMM_WORLD);
    MPI_Pack(AM,10,MPI_CHAR,a,1000,&position,MPI_COMM_WORLD);
    MPI_Send(a,position,MPI_PACKED,rank+1,WORKTAG,MPI_COMM_WORLD);
    printf(" RANK: %d of %d\n",rank,size);
}
//gethostname(hostname,100);

if(rank<(size-1)) {
    
    MPI_Send(a,1000,MPI_CHAR,rank+1,WORKTAG,MPI_COMM_WORLD);
    

}

if(rank==(size-1)) {
    
    MPI_Unpack(a,1000,&position,fnameF,20,MPI_CHAR,MPI_COMM_WORLD);
    MPI_Unpack(a,1000,&position,lnameF,20,MPI_CHAR,MPI_COMM_WORLD);
	MPI_Unpack(a,1000,&position,&ageF,1,MPI_INT,MPI_COMM_WORLD);
	MPI_Unpack(a,1000,&position,AMF,10,MPI_CHAR,MPI_COMM_WORLD);
	printf(" Final message: %s  %s %d %s\n",fnameF,lnameF,ageF,AMF);

}



MPI_Finalize();
}
