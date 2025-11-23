#include<stdio.h>
#include<string.h>
void reverseRec(char*s,int l,int r)
{
    if(l>=r)return;
    char t=s[l];
    s[l]=s[r];
    s[r]=t;
    reverseRec(s,l+1,r-1);
}
int isPal(char*s)
{
    int i=0,j=strlen(s)-1;
    while(i<j)
    {
        if(s[i]!=s[j])return 0;
        i++;j--;
    }
    return 1;
}
int main()
{
    char w[200];
    int t;
    printf("how many words:");
    scanf("%d",&t);
    while(t--)
    {
        printf("enter:");
        scanf(" %199[^\n]",w);
        char copy[200];
        strcpy(copy,w);
        reverseRec(copy,0,strlen(copy)-1);
        printf("reversed:%s\n",copy);
        if(isPal(w))printf("palindrome\n");
        else printf("not palindrome\n");
    }
    return 0;
}
