#include <stdio.h>
#define MAX_ROUNDS 50
int getTotal(int arr[], int count)
{
    if (count == 0)
        return 0;
    return arr[count - 1] + getTotal(arr, count - 1);
}
int main()
{
    int t, r, teamCount, roundCount;
    printf("Enter number of teams: ");
    scanf("%d", &teamCount);
    printf("Enter number of rounds: ");
    scanf("%d", &roundCount);
    for (t = 0; t < teamCount; t++)
    {
        int roundScores[MAX_ROUNDS];
        for (r = 0; r < roundCount; r++)
        {
            printf("Team %d, Round %d score: ", t + 1, r + 1);
            scanf("%d", &roundScores[r]);
        }
        int totalScore = getTotal(roundScores, roundCount);
        printf("Team %d total = %d\n", t + 1, totalScore);
        int limit;
        printf("Enter threshold: ");
        scanf("%d", &limit);
        if (totalScore > limit)
            printf("Team %d passed threshold\n", t + 1);
        else
            printf("Team %d did not pass\n", t + 1);
    }
    return 0;
}

