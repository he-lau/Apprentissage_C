#include <stdio.h>
#include <stdbool.h> // Blibliothèque booléen
#include <math.h>
#include <complex.h>



int taille_chaine_car(char s[]) {
  int i=0;

  while (s[i]!='\0') { // \0 --> rajouter en fin de chaine par la machine
    printf("caractere d'incdice %d = %c, code ASCII = %d\n", i, s[i], s[i]);
    i++;
  }
  return i;
}

int main(void)
{



// TEST COURS
printf("-----------------------------------------------------------------\n");
printf("TEST RAPPELS \n");
printf("-----------------------------------------------------------------\n");

int age = 15;

bool age_majeur = (age>=18) ? true : false; // Affectation avec val retournée par la condition if

if (age_majeur)
    printf("18+ \n");
else
    printf("-18 \n");

int i = 0;

while (i < 3)
{
    printf("hello while ! \n");
    i++;
}

printf("i=%d \n",i);
do
{
    printf("hello do ! \n");
    i++;
} while (i < 3);

for (i = 0; i < 3; i++)
{
    printf("hello for ! \n");
    //break; --> permet de sortir de la boucle
}






// Exercice 1
printf("-----------------------------------------------------------------\n");
printf("EXERCICE 1 \n");
printf("-----------------------------------------------------------------\n");

int x1 = 100;
char y1;
y1=x1;
printf("x1=%d\ny1=%d\n",x1,y1); // OUTPUT: x1=100, y1=100

char x2 = 10;
int y2;
y2=x2;
printf("x2=%d\ny2=%d\n",x2,y2); // OUTPUT: x2=10, y2=10

// Exercice 2
printf("-----------------------------------------------------------------\n");
printf("EXERCICE 2 \n");
printf("-----------------------------------------------------------------\n");

char carALire;

printf("Saisir un caractère: \n");
scanf("%c",&carALire);
//carALire = getchar();

printf("code ASCII de \"%c\": %d \n",carALire, carALire);




// Exercice 3
printf("-----------------------------------------------------------------\n");
printf("EXERCICE 3 \n");
printf("-----------------------------------------------------------------\n");

int taille_tab;

printf("Saisir le nombre d'entiers à saisir. \n");
scanf("%d",&taille_tab);


int tab[taille_tab];

for (i=0; i<taille_tab; i++) {
  printf("Saisir la %d (ère/ ème) valeur :\n", i+1);
  scanf("%d", &tab[i]);
}

int tab_inverse[taille_tab];

for (i=0; i<taille_tab; i++) {
  tab_inverse[i]=tab[(taille_tab-1)-i]; // taille_tab-1 --> indice max
}

printf("Le tableau inversé : \n");

for (i = 0; i < taille_tab; i++) {
  printf("-%d-\t\n", tab_inverse[i]); // \t -- > tabulation ("espace") horizontale
}




// Exercice 4
printf("-----------------------------------------------------------------\n");
printf("EXERCICE 4 \n");
printf("-----------------------------------------------------------------\n");

char chaine[256];

printf("Saisir la chaîne de caractère: \n");
scanf("%s",chaine);
int taille = taille_chaine_car(chaine);
printf("Taille de \"%s\": %d \n", chaine, taille);


// Exercice 5
printf("-----------------------------------------------------------------\n");
printf("EXERCICE 5 \n");
printf("-----------------------------------------------------------------\n");

// ax^2+bx+c = 0

int a; int b; int c;
double res1;
double res2;
double complex resi1;
double complex resi2;

int nbre_res = 0;
bool imaginaire = false;


printf("Saisir suivant l'ordre abc les valeurs pour la resolution de l'expression ax^2+bx+c = 0\n");
scanf("%d %d %d", &a, &b, &c);


if (a != 0) {

  int d = (b*b)-(4*a*c);


  printf("Discriminant = %d\n", d);

  if (d>0) {
    nbre_res = 2;
    res1 = (-b+sqrt(d))/(2*a);
    res2 = (-b-sqrt(d))/(2*a);
  }
  else if (d==0) {
    nbre_res = 1;
    res1 = (-b)/(2*a);
  }
  else {

    if (b != 0) {
      imaginaire = true;
      nbre_res = 2;

      resi1 = (-b+I*sqrt(-d))/(2*a); // -d car racine carré d'un nombre nég n'est pas possible !!!!
      resi2 = (-b-I*sqrt(-d))/(2*a);
    }
    else {
      imaginaire = true;
      nbre_res = 2;
      resi1 = (I*sqrt(-d))/(2*a);
      resi2 = -(I*sqrt(-d))/(2*a);
    }

  }


  if (nbre_res==0) {
    printf("Pas de solution dans l'ensemble des reels.\n");
  }
  else if (nbre_res==1) {
    printf("1 solution:\n");
    printf("Solution de l'equation: %.2f \n", res1);
  }
  else if (nbre_res==2 && imaginaire == false) {
    printf("2 solutions:\n");
    printf("Solutions de l'equation: %.2f, %.2f \n", res1, res2);
  }

  if (imaginaire==true) {
    printf("Solutions de l'equation: %.1f%+.1fi, %.1f%+.1fi \n", creal(resi1), cimag(resi1), creal(resi2), cimag(resi2));
  }

}

else if (a==0 && b!=0) {
  printf("1 solution (polynome de degre 1):\n");
  res1 = (-c)/b;
  printf("Solution de l'equation: %.2f \n", res1);
}

else if(a==0 && b ==0 ) {
  printf("Pas de solutions (division par 0).");
}


    return 0;
}
