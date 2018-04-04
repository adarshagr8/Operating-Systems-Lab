#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int log_size, phy_size, page_size, i, j, x, ch=1, flag, pages, frames, log_addr, phy_addr, log_page_no, phy_page_no, offset;
	printf("enter logical memory size: ");
	scanf("%d",&log_size);
	printf("enter physical memory size: ");
	scanf("%d",&phy_size);
	printf("enter page size: ");
	scanf("%d",&page_size);
	pages=log_size/page_size;
	frames=phy_size/page_size;
	int page_table[pages];
	printf("enter page table:\n");
	for(i=0;i<pages;i++)
	{
		printf("page no. %d\tframe no. ",i);
		scanf("%d",&x);
		if(x>=frames || x<-1)
		{
			printf("\nerror: frame number doesn't exist\n\n");
			i--;
		}
		else
		{
			if(x==-1)
			{
				page_table[i]=x;
			}
			else
			{
				for(j=0,flag=0;j<i;j++)
				{
					if(page_table[j]==x)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
					printf("\nerror: cannot allocate multiple pages to the same frame\n"), i--;
				else
					page_table[i]=x;
			}
		}
	}
	while(ch)
	{
		printf("enter logical address: ");
		scanf("%d",&log_addr);
		if(log_addr>=log_size || log_addr<0)
		{
			printf("\nerror: logical address doesn't exist\n");
		}
		else
		{
			log_page_no = log_addr / page_size;
			if(page_table[log_page_no]==-1)
			{
				printf("\nerror: page no. %d does not correspond to any frame\n",log_page_no);
			}
			else
			{
				phy_page_no = page_table[log_page_no];
				offset = log_addr % page_size;
				phy_addr = phy_page_no*page_size + offset;
				printf("physical address: %d\n",phy_addr);
			}
			printf("\nenter 0 to exit: ");
			scanf("%d",&ch);
		}
	}	
}