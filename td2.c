#include <stdio.h>
#include<stdlib.h>
#include<string.h>


/*

  Pointeurs : variable contenant l'adresse d'une autre variable

  [VARIABLES]
    mavariable : valeur de la variable
    &mavariable : adresse de la variable

  [POINTEURS]

    *monPointeur = NULL ou *monPointeur = &maVariable
    (déclaration et initialisation d'un pointeur)


    monPointeur : adresse de la variable pointée
    *monPointeur : valeur de la variable pointée
    &monPointeur : adresse du pointeur

*/

void fct(char t[], int nb) {
  int i;
  for (i = 0; i < nb; i++) {
    printf("%c", t[i]);
  }
  printf("\n");
}

void fct1(char *t, int nb) {
  int i;
  for (i = 0; i < nb; i++) {
    printf("%c", t[i]);
  }
  printf("\n");
}

double moyenne_tab(double tab[], int n) {
  double somme = tab[0];
  for (int i = 1; i < n; i++) {
    somme += tab[i];
  }
  return (somme/n);
}

void supp_sans_motif(char source[]) {
  int i, j;
  char courant;

  for (i = 0; i < strlen(source); i++) {
      courant = source[i];
        for (j = i+1; j < strlen(source); j++) {
          if (courant==source[j]) {
            // TODO : fonction remove_char avec pointeur
            memmove(& source[i], & source[i + 1], strlen(source) - i);
            printf("%c\n", courant);
            return;
          }
      }
}
}


void supp(char motif, char source[]) {
  int i, j;
  int rep = 0; // bool
  int i_motif = -1;

  for (i = 0; i < strlen(source); i++) {

      if (source[i]==motif) {
        i_motif = i;
      }

        for (j = i+1; j < strlen(source); j++) {

          if (motif==source[j]) {
            rep = 1;
          }

          if (rep==1 && i_motif!=-1) {

            // TODO : fonction remove_char avec pointeur
            memmove(& source[i_motif], & source[i_motif + 1], strlen(source) - i_motif);

            return;
          }
      }
}
} // supp()

void supptout(char c, char str_in[]) {
   char *str=str_in; // pointeur sur la chaîne
   int id_read, id_write;
   id_read = 0;
   id_write = 0;

   while (str[id_read] != '\0')
   {
      // On parcours la chaîne tant que on ne trouve pas de char different du motif
      if (str[id_read] != c)
      {
        // On remplace le char
          str[id_write] = str[id_read];
          //
          id_write++;
      }
      id_read++;
    }
    str[id_write] = '\0';
}


int main(int argc, char const *argv[]) {


  printf("-----------------------------------------------------------------\n");
  printf("TEST\n");
  printf("-----------------------------------------------------------------\n");

  int a = 5;
  int *p = &a;
  printf("Adresse du pointeur : %p, valeur de la variable pointee : %d, adresse de la variable pointee : %p\n",&p, *p, p);

  int i;

  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 1 \n");
  printf("-----------------------------------------------------------------\n");

  char T[20];
  char T2[]="abcdefg";
  char *TP;

  TP=&T[0];
  T[0]='1'; T[1]='2'; T[2]='3'; T[3]='4'; T[4]='5';

  fct(T,3); // OUTPUT: 1, 2, 3
  fct1(T,3); // OUTPUT: 1, 2, 3
  fct(T2,3); // OUTPUT: a, b, c, d, e

  TP = &T2[3];

  fct(T,3); // OUTPUT: d, e, f
  fct1(T,3); // OUTPUT: d, e, f

  T[3] = '0';

  fct(T,5);
  printf("Saisir valeur de T : \n");
  scanf("%s", T);

  printf("%s\n", T);
  printf("%c\n", T[4]);

  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 2 \n");
  printf("-----------------------------------------------------------------\n");

  unsigned short tab[3] = {100, 200, 300};
  unsigned short *v;
  //unsigned char *v;

  v = tab;

  printf("%d \n", *(v));
  printf("%d \n", *(v+1));
  printf("%d \n", *(v+2));

 *(v+1)=500;

  printf("\n");

  for (i = 0; i < 3; i++) {
    printf("Tab[%d] = %d \n", i, tab[i]);
  }

  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 3 \n");
  printf("-----------------------------------------------------------------\n");

  double tab_test_moyenne[] = {5.6,7.9,8.5};

  printf("TEST moyenne_tab : %.2lf\n",moyenne_tab(tab_test_moyenne, 3));

  printf("-----------------------------------------------------------------\n");

  int mat1[2][2] = {{1, 2},
                    {3, 4}};
  int mat2[2][2] = {{5, 6}, {7, 8}};

  // 19, 22, 43, 50

  // TODO : produit matriciel


  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 4 \n");
  printf("-----------------------------------------------------------------\n");

  char motif = 'o';
  char source[] = "pookemon";
  printf("AVANT supp : %s\n", source);
  printf("motif : %c\n", motif);
  supp(motif, source);
  printf("APRES supp : %s\n", source);


  printf("-----------------------------------------------------------------\n");
  printf("EXERCICE 5 \n");
  printf("-----------------------------------------------------------------\n");

  char motif_tout = 'i';
  char source_tout[] = "iikguuuiiiuii";
  printf("AVANT supptout : %s\n", source_tout);
  printf("motif : %c\n", motif_tout);
  supptout(motif_tout, source_tout);
  printf("APRES supptout : %s\n", source_tout);




  return 0;
}
