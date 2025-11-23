#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char itemName[60];
    char category[40];
    int quantity;
};

void searchByCategory(struct Item *arr, int count, char *targetCat)
{
    int i, found = 0;

    for (i = 0; i < count; i++)
    {
        if (strcmp(arr[i].category, targetCat) == 0)
        {
            printf("%s %s %d\n",
                   arr[i].itemName,
                   arr[i].category,
                   arr[i].quantity);
            found = 1;
        }
    }

    if (!found)
        printf("none\n");
}

void searchByQuantity(struct Item *arr, int count, int minQty)
{
    int i, found = 0;

    for (i = 0; i < count; i++)
    {
        if (arr[i].quantity >= minQty)
        {
            printf("%s %s %d\n",
                   arr[i].itemName,
                   arr[i].category,
                   arr[i].quantity);
            found = 1;
        }
    }

    if (!found)
        printf("none\n");
}

int main()
{
    struct Item inventory[MAX_ITEMS];
    int i, total;

    printf("Number of items: ");
    scanf("%d", &total);

    for (i = 0; i < total; i++)
    {
        printf("Item name: ");
        scanf(" %59[^\n]", inventory[i].itemName);

        printf("Category: ");
        scanf(" %39[^\n]", inventory[i].category);

        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
    }

    char catSearch[40];
    printf("Category to search: ");
    scanf(" %39[^\n]", catSearch);

    searchByCategory(inventory, total, catSearch);

    int qtySearch;
    printf("Minimum quantity: ");
    scanf("%d", &qtySearch);

    searchByQuantity(inventory, total, qtySearch);

    return 0;
}

