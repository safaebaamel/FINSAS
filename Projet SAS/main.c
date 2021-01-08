#include "election.h"

int main(int ac, char **av)
{
    int i, j, k, num, n;
    char tab[50], nom, dest[n];

    i, j = 0;
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    printf("---------- E L E C T I O N S ---------------\n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");

    printf("These elections are final, please no that any error in choosing the candidat cannot be fixed! \nPlease make sure to check your choice before submiting!\n");
    printf("\n");
    printf("Let the HUNGER GAME BEGINS\n");

    printf("\n");
    printf("Go ahead and submit how many people want to submit!!\n");
    scanf("%d", &n);

    while (i < n)
    {
        printf("The president number %d: ", i);
        scanf("%s", &tab[i++]);
        printf("i = %d, nom = %s\n", i, tab[i]); //controle des entrées dans tab[i]
    }
    printf("\n");
    /* affichage du tableau*/

    for (i = 0; i < n ;i++)
    {
        printf("%s\n", tab[i]);
    }

    return 0;
}