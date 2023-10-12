#include <stdio.h>

void printTable(int td2, int td1, int td, int fg, int s)
{
    printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d FG, %d Safety\n",td2, td1, td, fg, s);
}
void findCombinations(int score)
{
    printf("Possible combinations of scoring plays:\n\n");
    for (int i = 0; i <= score / 8; i++)
    {
        for (int j = 0; j <= score / 7; j++)
        {
            for (int k = 0; k <= score / 6; k++)
            {
                for (int l = 0; l <= score / 3; l++)
                {
                    for (int m = 0; m <= score / 2; m++)
                    {
                        int total = (i * 8) + (j * 7) + (k * 6) + (l * 3) + (m * 2);
                        if (total == score)
                        {
                            printTable(i,j,k,l,m);
                        }
                    }
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int score;
    while (1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score == 0 || score == 1)
        {
            break;
        }
        else
        {
            printf("\n");
            findCombinations(score);
        }
    }
    return 0;
}
