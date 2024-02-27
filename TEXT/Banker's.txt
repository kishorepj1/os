#include <stdio.h>
int main()
{
    int n, r, i, j, k, p, u = 0, a = 0, nv;
    int block[10], min[10], max[10][10], resalloc[10][10], totalloc[10], totex[10], cs[10];
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    printf("Enter the no of resource classes: ");
    scanf("%d", &r);
    printf("Enter the total existed resources: ");
    for(k = 1; k <= r; k++)
    {
        scanf("%d", &totex[k]);
    }
    printf("Enter the allocated resources: ");
    for(i = 1; i <= n; i++)
    {
        printf("process %d:\n", i);
        for(k = 1; k <= r; k++)
        {
            scanf("%d", &resalloc[i][k]);
        }
    }
    printf("Enter the process making the new request: ");
    scanf("%d", &p);
    printf("Enter the requested resources: ");
    for(k = 1; k <= r; k++)
    {
        scanf("%d", &newreq[k]);
    }
    printf("Enter the processes which are blocked or running: ");
    for(i = 1; i <= n; i++)
    {
        if(i != p)
        {
            printf("process %d:\n", i + 1);
            scanf("%d%d", &block[i], &run[i]);
        }
    }
    block[p] = 0;
    run[p] = 0;
    for(k = 1; k <= r; k++)
    {
        j = 0;
        for(i = 1; i <= n; i++)
        {
            totalloc[k] = j + resalloc[i][k];
            j = totalloc[k];
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(block[i] == 1 || run[i] == 1)
        {
            active[i] = 1;
        }
        else
        {
            active[i] = 0;
        }
    }
    for(k = 1; k <= r; k++)
    {
        resalloc[p][k] += newreq[k];
        totalloc[k] += newreq[k];
    }
    for(k = 1; k <= r; k++)
    {
        if(totex[k] - totalloc[k] < 0)
        {
            u = 1;
            break;
        }
    }
    if(u == 0)
    {
        for(k = 1; k <= r; k++)
        {
            simalloc[k] = totalloc[k];
        }
        for(s = 1; s <= n; s++)
        {
            for(i = 1; i <= n; i++)
            {
                if(active[i] == 1)
                {
                    j = 0;
                    for(k = 1; k <= r; k++)
                    {
                        if((totex[k] - simalloc[k]) < (max[i][k] - resalloc[i][k]))
                        {
                            j = 1;
                            break;
                        }
                    }
                    if(j == 0)
                    {
                        for(k = 1; k <= r; k++)
                        {
                            simalloc[k] += resalloc[i][k];
                        }
                        active[i] = 0;
                    }
                }
            }
        }
        for(i = 1; i <= n; i++)
        {
            if(active[i] == 1)
            {
                a = 1;
                break;
            }
        }
        if(a == 1)
        {
            printf("Deadlock will occur");
        }
        else
        {
            printf("No deadlock will occur");
        }
    }
    else
    {
        printf("Deadlock will occur");
    }
    return 0;
}
