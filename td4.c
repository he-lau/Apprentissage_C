#include <stdio.h>
#include<string.h>


void prenom(FILE *fichier) {

  int carCourant=0;

  fseek(fichier, 0, SEEK_SET);

    do {
      carCourant = fgetc(fichier);
      printf("%c", carCourant);
    } while((carCourant !=' ') && (carCourant != EOF));

    printf("\n");

}

void copie(FILE *fs, FILE *fd) {

  int c;
  while ( (c=fgetc(fs)) != EOF) {
    fputc(c, fd);
  }

}

int compte_c(FILE *fichier) {

  fseek(fichier, 0, SEEK_SET);

  int compteur = 0;

      /* parcours du fichier */
      while(fgetc(fichier) != EOF)
        compteur ++; /* incrémentation du compteur */
  /* fermeture du fichier */
  fclose(fichier);
  return compteur;


}

int compte_m(FILE *fichier) {

  fseek(fichier, 0, SEEK_SET);

  int compteur = 1; // dernier mot sans espace

      /* parcours du fichier */
      while(fgetc(fichier) != EOF) {
        if(fgetc(fichier)==' ')
            compteur ++; /* incrémentation du compteur */
      }

  return compteur;

}

int compte_l(FILE *fichier) {

  int compteur = 1;

//  fseek(fichier, 0, SEEK_SET);

while(fgetc(fichier) != EOF) {
  if(fgetc(fichier)=='\n')
      compteur++;
}


 	return compteur;
}




int main(int argc, char const *argv[]) {

  FILE *f = fopen("./exo1.txt", "r");

  if (f != NULL) {
    prenom(f); // prenom
    prenom(f); // prenom
    fclose(f);
  }
  else
    printf("ERROR NO SUCH FILE\n");

  f = fopen("./copie_td4.c", "w");
  FILE *f1 = fopen("./td4.c", "r");

  copie(f1, f);

  fclose(f1);
  fclose(f);

  // EXERCICE 3

  f = fopen("./test_td4exo3.txt", "r");
  printf("compte_c : %d\n", compte_c(f));
  fclose(f);
  f = fopen("./test_td4exo3.txt", "r");
  printf("compte_m : %d\n", compte_m(f));
  fclose(f);
  f = fopen("./test_td4exo3.txt", "r");
  printf("compte_l : %d\n", compte_l(f));
  fclose(f);

   printf("nombre d'arguments : %d\n", argc);
   printf("arg indice 1 : %s\n", *argv[1]);

  if (argc == 3) {
    f = fopen(argv[1],"r");

    if (f != NULL) {
      if (*argv[2] == 'c')
        printf("nombre de caractere : %d\n", compte_c(f));
      if (*argv[2] == 'm')
        printf("nombre de mots : %d\n", compte_m(f));
      if (*argv[2] == 'l')
        printf("nombre de lignes : %d\n", compte_l(f));

    }
  }











  return 0;
}
