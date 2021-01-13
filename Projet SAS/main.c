#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int global_n_pres, global_n_voters;
float voting_pourc;
// vote*100/global_n_pres >= 15 

// typedef struct votemachine{
//     char tab[10];
//     int action;
// } votemachine;

typedef struct presidents{
    int votec;
    char id[10];
    char name[20];
    int status;
    int pp;
}presidents, temp;

struct presidents president[20];

typedef struct voters {
    char cin[20];
    char name[20];
    int vote;
    // struct votemachine v;
}voters;

struct voters voter[20];

void    ft_adding_presidents() {
    int subm_pres, i,j;

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

    printf("---------------------------------\n");
    printf("This year!! We have %d nominees!!\n", subm_pres);
    printf("Good luck for you all :)!\n");
    printf("---------------------------------\n");

    // The list of the presidents with their ids and names
    // free(president);

    for (i = 0; i < subm_pres; i++) {
        printf("Name: %s -- ID: %d\n", president[i].name, i);
        president[i].status = 1;
    // status == 1 from first tour
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
        printf("\nName: %s -- ID: %s\n", voter[i].name, voter[i].cin);
    }
}

void    ft_freevotes() {
    int i = 0;

    for (i = 0; i < global_n_pres; i++) {
            president[i].votec = 0; 
    }
}

void    ft_free_elim() {
    int i = 0;

    for (i = 0; i < global_n_pres; i++) {
        president[i].status = 0;
    }
}

void    ft_colvotes() {
    int i,j;
    int *stock;

    printf("\nTime for collecting votes!\n");
    printf("--------------------------\n");
    printf("\nChoose from the list below!!\t[WARNING]: MAKE SURE TO CHECK YOUR ANSWER BEFORE SUBMITING!\n");
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].status == 1) {
            printf("NAME: %s -- ID: %d\n", president[i].name, i);
        }
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

void    ft_colvotes2() {
    int i,j;
    int *stock;

    ft_freevotes();
    printf("\nTime for collecting votes 2!\n");
    printf("--------------------------\n");
    printf("\nChoose from the list below!!\n");
    printf("\n----------------------------\n");
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].status == 0) {
            printf("NAME: %s -- ID: %d\n", president[i].name, i);
        }
    }
    printf("\n----------------------------\n");
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

void    ft_colvotes3() {
    int i,j;
    int *stock;

    ft_freevotes();
    printf("\nTime for collecting votes 3!\n");
    printf("--------------------------\n");
    printf("\nChoose from the list below!!\n");
    printf("\n----------------------------\n");
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].status == 0) {
            printf("NAME: %s -- ID: %d\n", president[i].name, i);
        }
    }
    printf("\n----------------------------\n");
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
    // in this function, we'll go through all the votes, calculate those with less than 15% of the total votes
    int i, j, check;

    check = 0;
    j = 0;
    
    // voting_pourc = (president[i].votec * 100) / global_n_pres;
    // calculating the pourcentage of the vote in each 
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].votec == (global_n_voters/global_n_pres)) {
                check++;
        } // 0 will pass!! 1 is eliminated!!! :) 
    }
    if (check == global_n_pres) { // testing if they all have the same pourcentage of vote!!
        printf("[|POURCENTAGES OF VOTES ARE EQUAL|]\n");
        return;
    }

    for (i = 0; i < global_n_pres; i++) {
        if ((president[i].votec * 100) / global_n_pres >= 15) {
            president[i].status = 0;
            j++;
            printf("\nCongrats for the president: %s with the ID: %d\nSee you in round 2!\n", president[i].name, i);
        } else {
            printf("\nnominee %s :Sorry, try next time\n", president[i].name);
            president[i].status = 1;
        } 
    }
    /* no next step if n_of_nominees is less than 3
    if (j < 3) {
        printf("[Oups]: We're sorry but you got to re-insert the votes!! We cannot continue with less than 3 nominees\n");
        ft_freevotes();
        ft_colvotes();
    } */
 }

void getLoser()
{
    int i=0, *min;
    struct presidents *p;
    p = &president[0];
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].votec < p->votec && president[i].status == 0) {
            p = &president[i];
        }
    }
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].votec == p->votec && president[i].status == 0)
        {
            president[i].status = 2;
        }
    } 
}

void getWinner()
{
    int i=0, *max;
    struct presidents *pw;
    pw = &president[0];
    ft_freevotes();
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].votec > pw->votec && president[i].status == 0) {
            pw = &president[i];
        }
    }
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].votec == pw->votec && president[i].status == 0)
        {
            printf("The winner is: %s with the ID: %d", president[i].name, i);
        }
    } 
}
 
void    ft_secondtour()
{
    int i,j, check, min,pp;
    
    j = 0;
    check = 0;
    int pr;
    
    for (i = 0; i < global_n_pres; i++) {
        if ((president[i].votec == (global_n_voters/global_n_pres)) && president[i].status == 0) {
                check++;
        } // :)
    }
    if (check == global_n_pres) { // testing if they all have the same pourcentage of vote!!
        printf("[|POURCENTAGES OF VOTES ARE EQUAL|]\n");
        return;
    }

    printf("Welcome to the second tour!\n");
    printf("The new list of the nominees\n");
    printf("\n-----------------------------");
    for (i = 0; i < global_n_pres; i++) {
        if (president[i].status == 0) {
            printf("name:%s\t Id:%d\t", president[i].name, i);
        }
    }
    printf("\n-------------------------------\n");
    // ft_freevotes();
    // ft_colvotes2();
    getLoser();
    // president[global_n_pres].status = 2; // min is gone :)!!!
    
    // for(int k=0;k<global_n_pres;k++)
        // printf("\nCongrats for the president: %s with the ID: %d\nSee you in round 3!\n", president[k].name, k);            
    
    printf("-------------------------\n");
    // new list of presids
    for (i = 0; i < global_n_pres; i++) {
         if (president[i].status == 0) {
             printf("\nName: %s -- ID: %d", president[i].name, i);
         }
    }
}

void    ft_thirdtour() {
    int i;

    printf("Welcome to the third tour!\n");
    printf("The new list of the nominees\n");
    printf("\n-------------------------------\n");
    // ft_freevotes();
    // ft_colvotes3();
    getWinner();
    printf("\n-------------------------\n");
   
   
}

void interfacedelapp(){

    // int expression;

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
    printf("* *              1)                                2)                            3)                          * *\n");
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
/*
    printf("Go ahead and choose one of the above\n");

    switch (expression)
    {
    case 1: 
        printf("Adding Presidents");
        ft_adding_presidents();
        break;
    case 2:
        printf("Adding Voters");
        ft_adding_voters();
        break;
    case 3:
        printf("Collecting Votes");
        ft_colvotes();
        break;
    case 4:
        printf("First Tour");
        ft_firsttour();
        break;
    case 5:
        printf("Second Tour");
        ft_secondtour();
        break;
    case 6: 
        printf("Last Tour");
        ft_thirdtour();
        break;
    default: 
        printf("ERROR!! try again later!!");
        return;
        break;
    }
    */
}

int	main() 
{
    // int n, m, i, j;

    
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
    printf("---------------------------");
    printf("\n");
    ft_firsttour();
    printf("---------------------------");
    printf("\n");
    ft_colvotes2();
    printf("----------------------------");
    printf("\n");
    ft_secondtour();
    printf("\n---------------------------");
    printf("\n");
    ft_colvotes3();
    printf("\n---------------------------");
    printf("\n");
    ft_thirdtour();

    return 0;
}
