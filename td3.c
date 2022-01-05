#include <stdio.h>
#include<stdlib.h>
#include<string.h>


/*

  STRUCTURE :

    Déclaration :

      struct var_struct {
        type var;
        type var;
        type var;
        ...
      };

      struct var_struct var;
      struct var_struct *var;

    Acces aux membres (attributs) :

      var.attribut;
      var -> attribut; (pointeur)

  -------------------------------------------------------------------------

  ALOOCATION DYNAMIQUE :


    sizeof(<donnee>)          : retourne la taille de la donnee en octet

    void * malloc(<taille en octet>) : allouer dynamiquement une zone mémoire, ne pas oublier de caster
    free(<donnee allouee>)    : libère la mémoire allouée

    exit() : pour quitter le programme si allocation echoue (null)

    calloc(<donnee>, <taille en octets>) : alloue et initialise tout à 0
    realloc(<donne>, <nouvelle taille>) : réalloue un espace mémoire

    %p : connaitre @

  --------------------------------------------------------------------------

  LISTES :





  ---------------------------------------------------------------------------

  PREPROCESSEUR :

  #define




*/

int main(int argc, char const *argv[]) {

  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 1 \n");
  printf("-----------------------------------------------------------------\n");

  void affiche_vecteur(int *vecteur, int dimension) {
    for (int i = 0; i < dimension; i++) {
      printf("%d\t", *(vecteur+i));
      //printf("%d\n", vecteur[i]);
    }
    printf("\n");
  }


  void affiche_matrice(int **matrice, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
      affiche_vecteur(matrice[i], colonnes);
    }
  }


  int dim = 3;
  int v1[3] = {1,2,3};

  //affiche_vecteur(v1, dim);

  int **m = malloc(dim * sizeof(int *));
  for (int i = 0; i < dim; i++) {
    m[i] = malloc(dim * sizeof(int));
    for (int j = 0; j < dim; j++) {
      m[i][j] = 1;
    }
  }

  affiche_matrice(m,dim,dim);



  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 2 \n");
  printf("-----------------------------------------------------------------\n");

  int *alloue_vecteur(int dim, int val) {
    int *vect;
    vect = (int *) malloc(dim*sizeof(int));
    for (int i = 0; i < dim; i++) {
      vect[i] = val;
    }
    return vect;
  }

  void liberer_vecteur(int* vecteur) {
    free(vecteur);
  }


  int *v;
  v = alloue_vecteur(3, 777);
  affiche_vecteur(v, 3);
  liberer_vecteur(v);

  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 3 \n");
  printf("-----------------------------------------------------------------\n");


  int **alloue_matrice(int lignes, int colonnes, int val) {
    int i, j;
    int **matrice = malloc(lignes*sizeof(int *));

    for (i = 0; i < lignes; i++) {
      matrice[i] = malloc (colonnes*sizeof(int));

      for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
          matrice[i][j] = val;
        }
      }
    }
    return matrice;
  }

  void libere_matrice(int **matrice, int lignes) {

    int i;
    for (i = 0; i < lignes; i++) {
      free(matrice[i]);
    }
    free(matrice);
  }



  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 4 \n");
  printf("-----------------------------------------------------------------\n");


  struct livre {
    char titre[50];
    int code;
    int prix;
  };

  struct livre * init(int n) {
    int i;

    struct livre *resultat = malloc(n*sizeof(struct livre));

    for (i = 0; i < n; i++) {
      resultat[i].titre[0] = '\0';
      resultat[i].code = 0;
      resultat[i].prix = 0;
    }
    return resultat;
  }

  void affiche_bib(int n, struct livre *bib);

  void echange_livre(int i, int j, struct livre * bib);

  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 5 \n");
  printf("-----------------------------------------------------------------\n");

  struct liste {
    int val;
    struct liste *ptr;
  };

  struct liste *cel1, *tete;
  int i;
  cel1 = (struct liste*) malloc(sizeof(struct liste));
  tete = cel1;
  //scanf("%d\n", &cell->val);
  cel1->val = 0;
  for (i = 1; i < 3; i++) {
    cel1->ptr = (struct liste*) malloc(sizeof(struct liste));
    cel1->ptr->val = i;
    cel1->ptr->ptr = NULL;
    cel1 = cel1->ptr;
  }
/*
  struct liste *cel, *celprec;
  celprec = NULL;
  for (i = 0; i < 3; i++) {
    cel = (struct liste*) malloc(sizeof(struct liste));
    cel->val = i;
    cel->ptr = celprec;
    celprec = cel;
  }
*/










///////////////////////////////////////////////////////////////////////////


/*
void liste_inverse_string() {

  char str[256];
  puts("Entrer une chaine  : ");
  gets(str);

  struct list *cel, *celprec;
  celprec = NULL;
  char *p = strtok(str, " ");

  char *p_courant;

  for (i = 0; i < strlen(str) & p!=NULL ; i++) {
    cel = (struct list*) malloc(sizeof(struct list));
    p_courant = p;
    cel->mot = p_courant;
    cel->ptr = celprec;
    celprec = cel;
    p = strtok(NULL, " ");
  }

  struct list *tmp = cel;
  i=0;
  while(tmp != NULL)
  {
    printf("element %d : %s \n",i, tmp->mot);
    tmp = tmp->ptr;
    i++;
  }

}

//liste_inverse_string();

*/



struct list {
  char *mot;
  struct list *ptr;
};


  void liste_inverse_string_2() {

    int n=3; // nbre d'éléments de la liste
    int i;

    char *str;
    struct list *cel, *celprec;
    celprec = NULL;

    /* Parcours n fois */
    for (i = 0; i < n; i++) {
      str = (char*)malloc(sizeof(char));
      puts("Entrer une chaine  : ");
      gets(str);

      /* Construction de la liste chaînée inversée */
      char *p = str;

      cel = (struct list*) malloc(sizeof(struct list));
      cel->mot = p;
      cel->ptr = celprec;
      celprec = cel;
      str = NULL; // pointe sur NULL pour pouvoir réaffecter
    }

    /* Affichage de la liste chaînée */
      struct list *tmp = cel;
      i=0;
      while(tmp != NULL)
      {
        printf("element %d : %s \n",i, tmp->mot);
        tmp = tmp->ptr;
        i++;
      }

  }

liste_inverse_string_2();







  return 0;
}
