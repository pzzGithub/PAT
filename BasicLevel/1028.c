#include<stdio.h>
#include<string.h>

int main()
{
    int N,count=0;
    char current[17],eldest[17]={'9'},youngest[17]={'0'};
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s %s",current+11,current);
        if(strcmp(current,"1814/09/06")>=0 && strcmp(current, "2014/09/06") <= 0)
        {
            if(strcmp(current, eldest) <= 0)
                memcpy(eldest, current, 17);
            if(strcmp(current, youngest) >= 0)
                memcpy(youngest, current, 17);
            count++;
        }
    }

    if(count)
        printf("%d %s %s", count, eldest + 11, youngest + 11);
    else
        printf("0");
    return 0;
}