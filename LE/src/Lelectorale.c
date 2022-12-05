#include <stdlib.h>
#include <stdbool.h>
#include "Lelectorale.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum{
	EID,
	ENOM,
	EORIENTATION,
	ENOMCT,
	ECINT,
	ENUMTEL,
	ECINC1,
	EGENREC1,
	ECINC2,
	EGENREC2,
	ECINC3,
	EGENREC3,
	ENBVOTE,
	EDATE,
	ECOLUMNS,
};

void ajouter(Lelectoral e){
    e.nbrVote = 0 ;
    FILE *f;
    f = fopen("listeE.txt","a");
    if(f!= NULL){
        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.num_tel,e.tab_cand[0].cin,e.tab_cand[0].genre,e.tab_cand[1].cin,e.tab_cand[1].genre,e.tab_cand[2].cin,e.tab_cand[2].genre,e.nbrVote,e.d.j,e.d.m,e.d.a);
    }
    fclose(f);
}


void supprimer(char id[]){
	Lelectoral e;
	FILE *f, *g;
	f=fopen("listeE.txt","r");
	g=fopen("temp.txt","a");
	if(f!=NULL&&g!=NULL){
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.num_tel,e.tab_cand[0].cin,e.tab_cand[0].genre,e.tab_cand[1].cin,e.tab_cand[1].genre,e.tab_cand[2].cin,e.tab_cand[2].genre,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
		{
			if(strcmp(e.id,id) != 0)
				fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.num_tel,e.tab_cand[0].cin,e.tab_cand[0].genre,e.tab_cand[1].cin,e.tab_cand[1].genre,e.tab_cand[2].cin,e.tab_cand[2].genre,e.nbrVote,e.d.j,e.d.m,e.d.a);
		}
		
		fclose(f);
		fclose(g);
		
		remove("listeE.txt");
		rename("temp.txt","listeE.txt");
		}
}
void modifier_listeE(Lelectoral el){
	Lelectoral e;
	FILE *f, *g;
	f=fopen("listeE.txt","r");
	g=fopen("temp.txt","a");
	if(f!=NULL&&g!=NULL){
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.num_tel,e.tab_cand[0].cin,e.tab_cand[0].genre,e.tab_cand[1].cin,e.tab_cand[1].genre,e.tab_cand[2].cin,e.tab_cand[2].genre,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF)
		{
			if(strcmp(e.id,el.id) != 0){
				fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.num_tel,e.tab_cand[0].cin,e.tab_cand[0].genre,e.tab_cand[1].cin,e.tab_cand[1].genre,e.tab_cand[2].cin,e.tab_cand[2].genre,e.nbrVote,e.d.j,e.d.m,e.d.a);
			}else{
				fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",el.id,el.nom,el.orientation,el.nomCT,el.cinT,el.num_tel,el.tab_cand[0].cin,el.tab_cand[0].genre,el.tab_cand[1].cin,el.tab_cand[1].genre,el.tab_cand[2].cin,el.tab_cand[2].genre,el.nbrVote,el.d.j,el.d.m,el.d.a);
			}
		}
		
		fclose(f);
		fclose(g);
		
		remove("listeE.txt");
		rename("temp.txt","listeE.txt");
		}
}
void afficher_election(GtkWidget *liste,char *fname){

}

/* ----------------------------------------------------------------------------------------- */

int rechercher_listeE(char id[]){
    Lelectoral e;
    FILE *f;
    f = fopen("listeE.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.num_tel,e.tab_cand[0].cin,e.tab_cand[0].genre,e.tab_cand[1].cin,e.tab_cand[1].genre,e.tab_cand[2].cin,e.tab_cand[2].genre,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
        	if(strcmp(e.id,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
    

}

/* ----------------------------------------------------------------------------------------- */

Lelectoral recherche_listeE(char id[]){
    Lelectoral e;
    FILE *f;
    f = fopen("listeE.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.num_tel,e.tab_cand[0].cin,e.tab_cand[0].genre,e.tab_cand[1].cin,e.tab_cand[1].genre,e.tab_cand[2].cin,e.tab_cand[2].genre,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
        	if(strcmp(e.id,id) == 0){
       		     return e;
        	}
    	}
}
    fclose(f);
    return;
}

/* ----------------------------------------------------------------------------------------- */

void afficher_listeE(GtkWidget *liste,char *fname){
    
  GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    Lelectoral e ;
    char nb[20];
	char dateFormat[100];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom LE",renderer,"text",ENOM,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Orientation",renderer,"text",EORIENTATION,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom Tête Liste",renderer,"text",ENOMCT,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin",renderer,"text",ECINT,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Numero Tel",renderer,"text",ENUMTEL,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin C1",renderer,"text",ECINC1,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Genre C1",renderer,"text",EGENREC1,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin C2",renderer,"text",ECINC2,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Genre C2",renderer,"text",EGENREC2,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("N° Cin C3",renderer,"text",ECINC3,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Genre C3",renderer,"text",EGENREC3,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre Vote",renderer,"text",ENBVOTE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date",renderer,"text",EDATE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d\n",e.id,e.nom,e.orientation,e.nomCT,e.cinT,e.num_tel,e.tab_cand[0].cin,e.tab_cand[0].genre,e.tab_cand[1].cin,e.tab_cand[1].genre,e.tab_cand[2].cin,e.tab_cand[2].genre,&(e.nbrVote),&(e.d.j),&(e.d.m),&(e.d.a))!=EOF){
			sprintf(nb,"%d",e.nbrVote);
			sprintf(dateFormat,"%d/%d/%d",e.d.j,e.d.m,e.d.a);
			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,e.id,ENOM,e.nom,EORIENTATION,e.orientation,ENOMCT,e.nomCT,ECINT,e.cinT,ENUMTEL,e.num_tel,ECINC1,e.tab_cand[0].cin,EGENREC1,e.tab_cand[0].genre,ECINC2,e.tab_cand[1].cin,EGENREC2,e.tab_cand[1].genre,ECINC3,e.tab_cand[2].cin,EGENREC3,e.tab_cand[2].genre,ENBVOTE,nb,EDATE,dateFormat,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}

    
}

/* ----------------------------------------------------------------------------------------- */

