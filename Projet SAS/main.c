#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global_n_pres, global_n_voters;

typedef struct votemachine{
    char tab[10];
    int action;
} votemachine;

typedef struct presidents{
    int votec;
    char id[10];
    char name[20];
}presidents;

struct presidents president[20];

typedef struct voters {
    char cin[20];
    char name[20];
    int vote;
    struct votemachine v;
}voters;

struct voters voter[20];

void    ft_adding_presidents() {
    int subm_pres, i;

    do {
        printf("Please make sure to put a number greater than or equal to 5\n");
        scanf("%d", &subm_pres);
    } while (subm_pres < 5);

    printf("STARTING THE SUBMIT!!!\n");
    for (i = 0; i < subm_pres; i++) 
    {
        printf("Enter the name: ");
        scanf("%s", &*president[i].name);
        printf("The ID of the president: %d\n", i);
    }
    global_n_pres = subm_pres;
    // global_n_pres = subm_pres;

    printf("This year!! We have %d nominees!!\n", subm_pres);
    printf("Good luck for you all :)!\n");

    // The list of the presidents with their ids and names
    // free(president);

    for (i = 0; i < subm_pres; i++) {
        printf("Name: %s -- ID: %d\n", president[i].name, i);
    }
}

void    ft_adding_voters() {
    int subm_voters, i;

    printf("Now, time to insert the voters!!\n");
    do {
        printf("Please make sure to put a number greater than or equal to 10\n");
        scanf("%d", &subm_voters);
    } while (subm_voters < 10);

    global_n_voters = subm_voters;

    printf("STARTING THE SUBMIT!!!\n");
    for (i = 0; i < subm_voters; i++) 
    {
        printf("Enter the CIN of the voter: \n");
        scanf("%s", &*voter[i].cin);
        printf("Enter the name of the voter: \n");
        scanf("%s", &*voter[i].name);
    }

    // global_n_pres = subm_pres;
    printf("\n");
    printf("----------------------------------");
    printf("\nThis year!! We have %d voters!!\n", subm_voters);
    printf("----------------------------------");


    // The list of the presidents with their ids and names
    // free(voter);
    
    for (i = 0; i < subm_voters; i++) {
        printf("Name: %s -- ID: %s\n", voter[i].name, voter[i].cin);
    }
}

void    ft_colvotes() {
    int i,j;
    int *stock;

    printf("\nTime for collecting votes!\n");
    printf("--------------------------\n");
    printf("\nChoose from the list below!!\n                         [WARNING]: MAKE SURE TO CHECK YOUR ANSWER BEFORE SUBMITING!\n");
    for (i = 0; i < global_n_pres; i++) {
        printf("NAME: %s -- ID: %d\n", president[i].name, i);    
    }
    printf("----------------------------");
    printf("\n");

    for (i = 0; i < global_n_voters; i++)
    {
        printf("Voter: %s with CIN: %s - Which president you choose ?\n", voter[i].name, voter[i].cin);
        scanf("%d", &voter[i].vote);
        stock = &voter[i].vote;
        president[*stock].votec++;
    }
    printf("VOTE SUCCEEDED!\n");    
}

 void   ft_firsttour()
 {
     int i, j;

     
 }


/* int    ft_isalpha(char *s)
{
    int i = 0;

    while (s[i++] != '\0') 
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i]<= 'z' && s[i] >= 'a')) 
            return 1;
        else
            return 0;
    }
} */

void interfacedelapp(){


printf("************************************************************************************************************** *\n");
printf("* ************************************************************************************************************ *\n");
printf("* * YOUCODE                                                                                      Safae Baamel* *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                    WELCOME TO THE E-VOTING APPLICATION                                   * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                          PROJECT END OF SAS                                              * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                :)                                                        * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                       ==============================                                     * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                 C IS FUN :)                                              * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                       ==============================                                     * *\n");
printf("* *                                                                                                          * *\n");
printf("* *                                                                                                          * *\n");
printf("* ************************************************************************************************************ *\n");
printf("************************************************************************************************************** *\n");
}

int	main() {
    int n, m, i, j;

    
    interfacedelapp();
    printf("These elections are final, please note that any error in choosing the candidat cannot be fixed! \nPlease make sure to check your choice before submiting!\n");
    printf("\n");
    printf("Let the HUNGER GAME BEGINS\n");

    printf("\n");
    ft_adding_presidents();
    printf("------------------------\n");
    ft_adding_voters();
    printf("\n");
    printf("---------------------------");
    ft_colvotes();
    return 0;
}
