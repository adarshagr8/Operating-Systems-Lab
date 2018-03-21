#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std ;
int main()
{
  int i, n, d[20], disk, diskp, seek=0, dloc;   
  float aver;
  cout<<"enter size of queue: ";
  cin>>n;
  cout<<"enter current position of head: ";
  cin>>disk;
  cout<<"enter previous position of head: ";
  cin>>diskp;
  cout<<"enter elements of disk queue:\n";
  for(i=0;i<n;i++)
  {
    cin>>d[i];
  }
  sort(d,d+n);
  if(disk>=d[0])
  {
    for(i=0;i<n;i++)   
    {
      if(disk<d[i]) 
      { 
        if(diskp>disk)
        {
          dloc=i-1; 
          break;
        }
        else
        {
          dloc=i;
        }  
      }
    }
    cout<<"move is from "<<disk<<" to "<<d[dloc]<<" with seek "<<abs(disk-d[dloc])<<endl;
    seek+=abs(disk-d[dloc]);
  }

  if(diskp>disk)
  {
    for(i=dloc;i>0;i--)
    { 
      cout<<"move is from "<<d[i]<<" to "<<d[i-1]<<" with seek "<<d[i]-d[i-1]<<endl;
      seek+=d[i]-d[i-1];
    }
    cout<<"move is from "<<d[i]<<" to "<<d[dloc+1]<<" with seek "<<d[dloc+1]-d[i]<<endl;
    seek+=d[dloc+1]-d[i];
    for(i=dloc+2;i<n;i++)
    {
      cout<<"move is from "<<d[i-1]<<" to "<<d[i]<<" with seek "<<d[i]-d[i-1]<<endl;
      seek+=d[i]-d[i-1];
    }
  }
  else
  {
    for(i=dloc+1;i<n;i++)
    {
      cout<<"move is from "<<d[i-1]<<" to "<<d[i]<<" with seek "<<d[i]-d[i-1]<<endl;
      seek+=d[i]-d[i-1];
    }
    cout<<"move is from "<<d[n-1]<<" to "<<d[dloc-1]<<" with seek "<<d[n-1]-d[dloc-1]<<endl;
    seek+=d[n-1]-d[dloc-1];
    for(i=dloc-1;i>0;i--)
    { 
      cout<<"move is from "<<d[i]<<" to "<<d[i-1]<<" with seek "<<d[i]-d[i-1]<<endl;
      seek+=d[i]-d[i-1];
    }
  }
  cout<<"total seek time is "<<seek<<endl;
  aver=seek/(float)n;
  cout<<"average seek time is "<<aver<<endl;
  return 0;
}