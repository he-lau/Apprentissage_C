#include <stdio.h>
#include<stdlib.h>
#include<string.h>

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

  int main(int argc, char const *argv[]) {

    liste_inverse_string_2();



    return 0;
  }
