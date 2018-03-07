#include <stdio.h>
#include <algorithm>
using namespace std;
struct block
{
	int size,rem_size,id;
};

bool compare(struct block b1, struct block b2)
{
    return (b1.size > b2.size);
}	
int main()
{
	int ms, nob, ef,n,k, mp[10],tif=0,sum=0;
	int i,j,p=0,max_block_size=0;

	printf("Enter the total memory available (in Bytes): ");
	scanf("%d",&ms);
	printf("Enter the number of blocks: ");
	scanf("%d", &nob);
	struct block b[nob];
	for(i=0;i<nob;i++)
	{
		printf("enter size of block%d: ",i+1);
		scanf("%d",&b[i].size);
		if(max_block_size<b[i].size)
			max_block_size=b[i].size;
		b[i].rem_size=b[i].size;
		b[i].id=i+1;
		sum+=b[i].size;
	}
	ef=ms;
	printf("\nEnter the number of processes -- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter memory required for process %d (in Bytes): ",i+1);
	scanf("%d",&mp[i]);
	}
	sort(b , b+nob, compare);
	printf("\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED BLOCK\tINTERNAL FRAGMENTATION");
	for(i=0;i<n && p<nob;i++)
	{
		start:
		printf("\n %d\t%d",i+1,mp[i]);
		for(j=0;j<nob;j++)
		{
			if(mp[i] > b[j].rem_size)
				continue;
			else
			{
				printf("\t\t\t%d\t\t%d",b[j].id,b[j].rem_size-mp[i]);
				tif = tif + b[j].rem_size-mp[i];
				b[j].rem_size=0;
				ef-=b[j].size;
				p++;
				break;
			}
		}
		if(j==nob)
			{
				if(mp[i]<=max_block_size)
				{
					printf("\nenter number of block to be emptied: ");
					scanf("%d",&k);
					for(j=0;j<nob;j++)
						if(b[j].id==k)
						{
							p--;
							if(b[j].rem_size==0)
								ef+=b[j].size;
							b[j].rem_size=b[j].size;
							break;
						}
					goto start;
				}
				else
					printf("\t\t\tNO");
			}
	}
	if(p==nob && i!=n)
	{
		printf("\nenter number of block to be emptied: ");
		scanf("%d",&k);
		for(j=0;j<nob;j++)
			if(b[j].id==k)
				{
					p--;
					if(b[j].rem_size==0)
						ef+=b[j].size;
					b[j].rem_size=b[j].size;
					break;
				}
		goto start;
	}						
	if(i<n)
		printf("\nMemory is Full, Remaining Processes cannot be accommodated");
	//printf("\n\nTotal Internal Fragmentation is %d",tif);
	printf("\nTotal External Fragmentation is %d\n",ef);
}
