#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std ;
int main()
{
  int i, sum=0, n, d[20], disk, seek=0, dloc,p,max;   
  float aver;
  cout<<"enter max range of disk: ";
  cin>>max;
  cout<<"enter size of queue: ";
  cin>>n;
  cout<<"enter position of head: ";
  cin>>disk;
  cout<<"enter elements of disk queue:\n";
  for(i=0;i<n;i++)
  {
    cin>>d[i];
  }
  sort(d,d+n);
  cout<<"move left(0) or right(1)?: ";
  cin>>p;
  for(i=0;i<n;i++)   
    {
      if(disk<=d[i]) 
      { 
        if(disk==d[i])
        {
          dloc=i;
          break;
        }
        else if(p==0)
        {
          dloc=i-1; 
          break;
        }
        else
        {
          dloc=i;
          break;
        }  
      }
    }
    cout<<"move is from "<<disk<<" to "<<d[dloc]<<" with seek "<<abs(disk-d[dloc])<<endl;
    seek+=abs(disk-d[dloc]);
  


  if(p==0)
  {
    for(i=dloc;i>0;i--)
    {
      cout<<"move is from "<<d[i]<<" to "<<d[i-1]<<" with seek "<<d[i]-d[i-1]<<endl;
      seek+=d[i]-d[i-1];
    }
    cout<<"move is from "<<d[i]<<" to 0 with seek "<<d[i]<<endl;
    cout<<"move is from 0 to "<<d[dloc+1]<<" with seek "<<d[dloc+1]<<endl;
    seek+=d[i]+d[dloc+1];
    for(i=dloc+2;i<n;i++)
    {
      cout<<"move is from "<<d[i-1]<<" to "<<d[i]<<" with seek "<<d[i]-d[i-1]<<endl;
      seek+=d[i]-d[i-1];
    }
  }
  else
  {
    for(i=dloc;i<n-1;i++)
    {
      cout<<"move is from "<<d[i]<<" to "<<d[i+1]<<" with seek "<<d[i+1]-d[i]<<endl;
      seek+=d[i+1]-d[i];
    }
    cout<<"move is from "<<d[i]<<" to "<<max<<" with seek "<<max-d[i]<<endl;
    cout<<"move is from "<<max<<" to "<<d[dloc-1]<<" with seek "<<max-d[dloc-1]<<endl;
    seek+=max+max-d[i]-d[dloc-1];
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