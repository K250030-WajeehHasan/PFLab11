#include <stdio.h>
#include <string.h>
#define MAX 100
struct Gift {
    char itemName[60];
    char category[30];
    float cost;
    int stock;
};
void readGifts(struct Gift arr[], int count)
{
	int i;
    for(i = 0; i < count; i++)
    {
        printf("Enter name: ");
        scanf(" %59[^\n]", arr[i].itemName);
        printf("Enter type: ");
        scanf(" %29[^\n]", arr[i].category);
        printf("Enter price: ");
        scanf("%f", &arr[i].cost);
        printf("Enter quantity: ");
        scanf("%d", &arr[i].stock);
    }
}
void printPriceAbove(struct Gift arr[], int count, float limit)
{
    int i, shown = 0;
    for(i = 0; i < count; i++)
    {
        if(arr[i].cost > limit)
        {
            printf("%s %s %.2f %d\n",
                   arr[i].itemName, arr[i].category,
                   arr[i].cost, arr[i].stock);
            shown = 1;
        }
    }
    if (!shown)
        printf("none\n");
}
void printQtyAbove(struct Gift arr[], int count, int limit)
{
    int i, shown = 0;
    for(i = 0; i < count; i++)
    {
        if(arr[i].stock > limit)
        {
            printf("%s %s %.2f %d\n",
                   arr[i].itemName, arr[i].category,
                   arr[i].cost, arr[i].stock);
            shown = 1;
        }
    }
    if (!shown)
        printf("none\n");
}
int main()
{
    struct Gift list[MAX];
    int total;
    printf("Total gifts: ");
    scanf("%d", &total);
    readGifts(list, total);
    float priceLimit;
    printf("Price limit: ");
    scanf("%f", &priceLimit);
    printf("Gifts with price above limit:\n");
    printPriceAbove(list, total, priceLimit);
    int qtyLimit;
    printf("Quantity limit: ");
    scanf("%d", &qtyLimit);
    printf("Gifts with quantity above limit:\n");
    printQtyAbove(list, total, qtyLimit);
    return 0;
}
