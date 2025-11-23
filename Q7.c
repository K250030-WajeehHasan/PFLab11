#include<stdio.h>
#include<string.h>
#define MAXU 100
struct Forecast
{
    char sign[20];
    char color[20];
    int lucky;
    char advice[120];
};
struct User
{
    char name[60];
    int day,month,year;
    char sign[20];
};
void assignSign(struct User*u)
{
    int d=u->day,m=u->month;
    if((m==3&&d>=21)||(m==4&&d<=19))strcpy(u->sign,"Aries");
    else if((m==4&&d>=20)||(m==5&&d<=20))strcpy(u->sign,"Taurus");
    else if((m==5&&d>=21)||(m==6&&d<=20))strcpy(u->sign,"Gemini");
    else if((m==6&&d>=21)||(m==7&&d<=22))strcpy(u->sign,"Cancer");
    else if((m==7&&d>=23)||(m==8&&d<=22))strcpy(u->sign,"Leo");
    else if((m==8&&d>=23)||(m==9&&d<=22))strcpy(u->sign,"Virgo");
    else if((m==9&&d>=23)||(m==10&&d<=22))strcpy(u->sign,"Libra");
    else if((m==10&&d>=23)||(m==11&&d<=21))strcpy(u->sign,"Scorpio");
    else if((m==11&&d>=22)||(m==12&&d<=21))strcpy(u->sign,"Sagittarius");
    else if((m==12&&d>=22)||(m==1&&d<=19))strcpy(u->sign,"Capricorn");
    else if((m==1&&d>=20)||(m==2&&d<=18))strcpy(u->sign,"Aquarius");
    else strcpy(u->sign,"Pisces");
}
void showHoroscope(struct User*u,struct Forecast f[])
{
    int i;
    for(i=0;i<12;i++)if(strcmp(f[i].sign,u->sign)==0)break;
    if(i==12)printf("no forecast\n");
    else
    {
        printf("%s's sign %s\n",u->name,u->sign);
        printf("color:%s\n",f[i].color);
        printf("lucky:%d\n",f[i].lucky);
        printf("advice:%s\n",f[i].advice);
    }
}
int findForecast(struct Forecast f[],int n,char*s)
{
    int i;
    for(i=0;i<n;i++)if(strcmp(f[i].sign,s)==0)return i;
    return -1;
}
int main()
{
    struct Forecast fc[12];
    int i;
    char *names[12]={"Aries","Taurus","Gemini","Cancer","Leo","Virgo","Libra","Scorpio","Sagittarius","Capricorn","Aquarius","Pisces"};
    for(i=0;i<12;i++){strcpy(fc[i].sign,names[i]);strcpy(fc[i].color,"blue");fc[i].lucky=7;strcpy(fc[i].advice,"have a good day");}
    struct User users[MAXU];
    int ucount=0;
    printf("how many users:");
    scanf("%d",&ucount);
    for(i=0;i<ucount;i++)
    {
        printf("name:");
        scanf(" %59[^\n]",users[i].name);
        printf("day month year:");
        scanf("%d%d%d",&users[i].day,&users[i].month,&users[i].year);
        assignSign(&users[i]);
    }
    int choice;
    while(1)
    {
        printf("\n1.show for user\n2.update forecast\n-1.exit\n:");
        scanf("%d",&choice);
        if(choice==-1)break;
        if(choice==1)
        {
            printf("which user index:");
            int idx;scanf("%d",&idx);
            if(idx<1||idx>ucount)printf("invalid\n");
            else showHoroscope(&users[idx-1],fc);
        }
        else if(choice==2)
        {
            printf("which sign:");
            char s[20];scanf(" %19s",s);
            int pos=findForecast(fc,12,s);
            if(pos==-1)printf("no sign\n");
            else
            {
                printf("color:");
                scanf(" %19s",fc[pos].color);
                printf("lucky:");
                scanf("%d",&fc[pos].lucky);
                printf("advice:");
                scanf(" %119[^\n]",fc[pos].advice);
                printf("updated\n");
            }
        }
        else printf("inv\n");
    }
    return 0;
}
