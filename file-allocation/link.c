#include <stdio.h>

struct file
{
 	char fname[10];
 	int start,size,block[20];
}f[10];
int main()
{
int i,j,n;
int blocks[20];
for(i=0;i<20;i++){
	blocks[i]=0;
}
printf("Enter no. of files:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 	printf("Enter file name:");
 	scanf("%s",f[i].fname);
 	s: printf("Enter starting block:");
 	scanf("%d",&f[i].start);
 	if(blocks[f[i].start]==1){
 		printf("\n---block already occupied---\n");
 		goto s;
 	}
 	f[i].block[0]=f[i].start;
 	blocks[f[i].start]=1;
 	printf("Enter no.of blocks:");
 	scanf("%d",&f[i].size);
 	printf("Enter block numbers:");
 	for(j=1;j<=f[i].size;j++)
 	{
    	scanf("%d",&f[i].block[j]);
        if(blocks[f[i].block[j]]==1 && j!=1){
       		printf("\n---block already occupied--\n");
          	j--;
        }
        else{
        	blocks[f[i].block[j]]=1;
        }
 	}
}
printf("File\tstart\tsize\tblock\n");
for(i=0;i<n;i++)
{
 	printf("%s\t%d\t%d\t",f[i].fname,f[i].start,f[i].size);      
 	for(j=1;j<=f[i].size-1;j++)
    	printf("%d--->",f[i].block[j]);
    printf("%d",f[i].block[j]);
   	printf("\n");
}
 

}


