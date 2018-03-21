#include <bits/stdc++.h>
#include <set>
#include <map>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    
    set<int> s;
    map<int, int> indexes;
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                set<int>::iterator it;
                for (it=s.begin(); it!=s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
    }
 
    return page_faults;
}
 
int main()
{
    int n,i,capacity;
    printf("enter number of pages: ");
    scanf("%d",&n);
    int pages[n];
    printf("enter page table capacity: ");
    scanf("%d",&capacity);
    printf("enter pages:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);
    printf("page faults: %d\n",pageFaults(pages, n, capacity));
    return 0;
}