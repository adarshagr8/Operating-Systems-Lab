#include <stdio.h>
#define M 100
void allocate();
void deallocate();
void display();
int tm,ch,ps,psa[M],start[M],end[M],hstart[M],hend[M],holes[M];
int p=1,i=1,pc=0,hc=1,k=1,flag=0;

main()
{
    printf("\nTotal memory(in Bytes) : ");
    scanf("%d",&tm);
    hstart[hc]=1;
    hend[hc]=tm;
    holes[hc]=tm;
    do{
     printf("\n1.Allocate\t2.Deallocate\t3.Display\t0.Exit : ");
     scanf("%d",&ch);
     switch(ch)
     {
            	case 1:	allocate();
                    	break;
                case 2:	deallocate();
                    	break;
                case 3:	display();
                    	break;
               	case 0:	goto end;
                default:printf("\nInvalid Choice ");
        }
     }while(ch!=0);
     end:;

}
void allocate()
{
    printf("\nProcess size(in Bytes): ");
    scanf("%d",&ps);
    for (i=1;i<=hc;i++)
        if (holes[i]>=ps)
            break;
    if(i==hc+1)
        printf("\nMemory not enough for process ");
    else
    {
        k=i;
        for (i=k+1;i<=hc;i++)
        {
            if(holes[i]>=ps && holes[i]<holes[k])
                    k=i;
        }
        pc++;
        psa[pc]=ps;
        start[pc]=hstart[k];
        end[pc]=hstart[k]+ps-1;
        hstart[k]=end[pc]+1;
        holes[k]=holes[k]-ps;
        if(hstart[k]==hend[k]+1)
            hstart[k]=hend[k]=holes[k]=-1;
        tm-=ps;
        printf("\nProcess Allocated : %d->%d  ",start[pc],end[pc]);
        if(!tm)
            hc=0;

    }
}
void deallocate()
{
    printf("\nProcess ID to deallocate : ");
    scanf("%d",&ch);
    if(ch>pc)
    {
        printf("\nNo such process exists  ");
        return;
    }
    printf("\nHole created between memory locations %d and %d",start[ch],end[ch]);
    hc++;
    hstart[hc]=start[ch];
    hend[hc]=end[ch];
    holes[hc]=psa[ch];
    tm=tm+psa[ch];
    start[ch]=end[ch]=psa[ch]=-1;
}
void display()
{
    printf("\nProcesses: ");
    printf("\nPID\t\tMemloc\tSize");
    for(i=1;i<=pc;i++)
        printf("\n%d\t\t%d->%d\t%d",i,start[i],end[i],psa[i]);
    printf("\n\nMemory Available = %d Bytes",tm);
    if(hc)
    {
        printf("\n\nHoles:");
        printf("\nHID\t\tMemloc\tSize");
        for(i=1;i<=hc;i++)
            printf("\n\n%d\t\t%d->%d\t%d",i,hstart[i],hend[i],holes[i]);
    }
    printf("\n\nExternal Fragmentation = %d Bytes\n",tm);
}