#include<stdio.h>
void countdown(int d)
{
    if(d<0)
	return;
    if(d==0){
	printf("0\n");
	return;
	}
    printf("%d\n",d);
    countdown(d-1);
}
int main()
{
    int i, j;
    printf("How many events: ");
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        int days;
        printf("Days left for event %d: ",i+1);
        scanf("%d",&days);
        printf("Countdown for event %d\n",i+1);
        countdown(days);
    }
    return 0;
}
