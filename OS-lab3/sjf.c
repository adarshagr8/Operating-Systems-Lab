#include<stdio.h>
struct process{
int no,at1,at0,bt,wt;};

void swap(struct process *xp, struct process *yp)
{
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_at(struct process p[],int s, int n)
{
   int i, j;
   for (i = s; i < n-1; i++)        
       for (j = s; j+1 <n; j++) 
           if (p[j].at1 > p[j+1].at1)
              swap(&p[j], &p[j+1]);
}

void sort_bt(struct process p[],int s, int n)
{
   int i, j;
   for (i = s; i < n-1; i++)        
       for (j = s; j+1 <n; j++) 
           if (p[j].bt > p[j+1].bt)
              swap(&p[j], &p[j+1]);
}
int main()
{
	int n,i,time,wait=0,j;
	printf("enter number of processes: ");
	scanf("%d",&n);
	struct process p[n];
	for(i=0;i<n;i++)
	{
		printf("enter P%d arrival time and burst time: ",i+1);
		scanf("%d%d",&p[i].at0,&p[i].bt);								//at0 = real    at1=changing
		p[i].no=i+1;
		p[i].wt=0;
		p[i].at1=p[i].at0;
	}
	sort_bt(p,0,n);
	/*for(i=0;i<n;i++)
	{
		printf("P%d at: %d\tbt: %d\n",p[i].no,p[i].at,p[i].bt);
	}*/
	sort_at(p,0,n);
	/*for(i=0;i<n;i++)
	{
		printf("P%d at: %d\tbt: %d\n",p[i].no,p[i].at,p[i].bt);
	}*/
	p[0].wt=0;
	time=p[0].bt+p[0].at0;
	
	printf("waiting times:\nP%d\t0\n",p[0].no);
	for(i=1;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(p[j].at1-time<0)
				{p[j].wt=time-p[j].at0;	p[j].at1=0;}
			else
				{p[j].at1-=time;}
		}
		sort_bt(p,i,n);
		
		sort_at(p,i,n);
		
		printf("P%d\t%d\ttime: %d\n",p[i].no,p[i].wt,time);
		time+=p[i].bt;
		wait+=p[i].wt;
		
	}
	printf("average waiting time: %f\n",(float)wait/n);
}
