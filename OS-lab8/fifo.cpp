#include <bits/stdc++.h>
#include <set>
#include <queue>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    set<int> s;
    queue<int> indexes;
 
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }
 
    return page_faults;
}

int main()
{
    int n,capacity,i;
    printf("enter number of pages: ");
    scanf("%d",&n);
    int pages[n];
    printf("enter page table capacity: ");
    scanf("%d",&capacity);
    printf("enter pages:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);
    printf("page faults: %d\n",pageFaults(pages, n, capacity));
}