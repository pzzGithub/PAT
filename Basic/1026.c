#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLK_TCK 100

int main()
{
    int beginTck,endTck;
    scanf("%d %d",&beginTck,&endTck);
    int totalTck=endTck-beginTck;
    int totalSec=totalTck%CLK_TCK>=CLK_TCK/2?totalTck/CLK_TCK+1:totalTck/CLK_TCK;
    int hh,mm,ss;
    ss=totalSec%60;
    mm=totalSec/60%60;
    hh=totalSec/60/60;
    printf("%02d:%02d:%02d",hh,mm,ss);
    return 0;
}