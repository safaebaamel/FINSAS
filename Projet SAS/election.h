#ifndef ELECTION_H
#define ELECTRION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void    ft_putchar(char c);
char    presidents_list(char *c, int n);
char    electors_list(char *c, int n);
int     ft_length(char *c);
void    ft_swap(int *a, int *b);
void    ft_firsttourelim(char *tab, int n);
void    ft_memdel(void **op);
void    ft_removelastelem(char *tab, int n);
void    ft_putstr(char s[]);
char    election(char *tab);
int     ft_strtolower(int c);
char    *ft_strcpy(char *src, char *dest);

#endif