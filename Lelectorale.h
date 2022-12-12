#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct 
{
	char cin[20];
	char genre[20];
}candidat;

typedef struct
{
	int j;
	int m ;
	int a ;
}date ;
typedef struct
{
    char id[20];
    char nom[20];
    char orientation[30];
    char nomCT[30];
    char cinT[20];
    char num_tel[20]; 
    candidat tab_cand[10];
    int nbrVote ;	
    date d ;
}Lelectoral;



void ajouter(Lelectoral e);
void supprimer(char id[]);
void modifier_listeE(Lelectoral el);
void afficher_listeE(GtkWidget *liste,char *fname);
void afficher_listeEVote(GtkWidget *liste,char *fname);

int rechercher_listeE(char id[]);

Lelectoral recherche_listeE(char id[]);

int verifNum(char c[]);

int trierLE(char *fname);

void rechercher_NomLE(char nom[]);
