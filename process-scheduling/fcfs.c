#include<stdio.h>
struct process{
int at,bt,wt;};

void swap(struct process *xp, struct process *yp)
{
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(struct process p[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)        
       for (j = 0; j < n-i-1; j++) 
           if (p[j].at > p[j+1].at)
              swap(&p[j], &p[j+1]);
}
 
int main()
{
	int n,i,time,wait=0;
	printf("enter number of processes: ");
	scanf("%d",&n);
	struct process p[n];
	for(i=0;i<n;i++)
	{
		printf("enter P%d arrival time and burst time: ",i+1);
		scanf("%d%d",&p[i].at,&p[i].bt);
	}
	sort(p,n);
	p[0].wt=0;
	time=p[0].bt;
	printf("waiting times:\nP1\t0\n");
	for(i=1;i<n;i++)
	{
		p[i].wt=time-p[i].at;
		if(p[i].wt<0)
			p[i].wt=0;
		time+=p[i].bt;
		wait+=p[i].wt;
		printf("P%d\t%d\n",i+1,p[i].wt);
	}
	printf("average waiting time: %f\n",(float)wait/n);
}
	
	
	
	
