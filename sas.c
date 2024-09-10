#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date
{
    int jour;
    int mois;
    int annee;
} date;

typedef struct etudient
{
    int numEtudient;
    char nom[20];
    char prenom[20];
    char departement[20];
    date dateNaissance;
    double note;
} etudient;

etudient tabEtudient[500];
int id = 0;

void menudepartement(int i)
{
    int choix;
    printf("*************** Menu Departement *****************\n");
    printf("Informatique Taper 1\n");
    printf("Physique Taper 2\n");
    printf("Droit Taper 3\n");
    printf("Economie Taper 4\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        strcpy(tabEtudient[i].departement, "Informatique");
        break;
    case 2:
        strcpy(tabEtudient[i].departement, "Physique");
        break;
    case 3:
        strcpy(tabEtudient[i].departement, "Droit");
        break;
    case 4:
        strcpy(tabEtudient[i].departement, "Economie");
        break;
    default:
        printf("Valeur invalide\n");
        menudepartement(i);
        break;
    }
}

void dateNaissance(int i)
{
    int j, m, an;
    do
    {
        printf("Entrer le jour : ");
        scanf("%d", &j);
        if (j <= 0 || j > 31)
            printf("Jour invalide. Essayez encore.\n");
    } while (j <= 0 || j > 31);

    do
    {
        printf("Entrer le mois : ");
        scanf("%d", &m);
        if (m <= 0 || m > 12)
            printf("Mois invalide. Essayez encore.\n");
    } while (m <= 0 || m > 12);

    do
    {
        printf("Entrer l'annee : ");
        scanf("%d", &an);
        if (an <= 1600 || an > 2024)
            printf("Annee invalide. Essayez encore.\n");
    } while (an <= 1600 || an > 2024);

    tabEtudient[i].dateNaissance.jour = j;
    tabEtudient[i].dateNaissance.mois = m;
    tabEtudient[i].dateNaissance.annee = an;
}

void ajouter()
{
    int nbrAjout, i;
    printf("Combien d'etudiants voulez-vous ajouter?\n");
    scanf("%d", &nbrAjout);

    if (nbrAjout <= 0)
    {
        printf("Veuillez entrer un nombre valide\n");
        return;
    }

    for (i = 0; i < nbrAjout; i++)
    {
        tabEtudient[id].numEtudient = ++id;
        printf("Entrer le nom : ");
        scanf("%s", tabEtudient[id - 1].nom);
        printf("Entrer le prenom : ");
        scanf("%s", tabEtudient[id - 1].prenom);
        dateNaissance(id - 1);
        menudepartement(id - 1);
        printf("Entrer la note globale : ");
        scanf("%lf", &tabEtudient[id - 1].note); // Corrected for double
    }
}

void afficher()
{
    int i;
    printf("******************** Affichage **********************\n");
    printf("_______________________________________________________________________________________________________________\n");
    printf("| Nom                 | Prenom               | Departement             | Date de naissance         | Note      |\n");

    for (i = 0; i < id; i++)
    {
        printf("_______________________________________________________________________________________________________________\n");
        printf("| %s | %s | %s | %d-%d-%d                | %.2f     |\n", tabEtudient[i].nom, tabEtudient[i].prenom, tabEtudient[i].departement, tabEtudient[i].dateNaissance.jour, tabEtudient[i].dateNaissance.mois, tabEtudient[i].dateNaissance.annee, tabEtudient[i].note);
        printf("_______________________________________________________________________________________________________________\n");
    }
}

void modifierNom()
{
    char newnom[20];
    int numetud;
   do{
        printf("Enter le numero de etudient que vous voulez modifier ses information : ");
        scanf("%d",&numetud);
        if(numetud<0 || numetud >id)
          printf("le numero d'etudient invalide . Essez de nouveau\n");
        
    }while(numetud<0 || numetud >id);

    printf("entrer le nouveau nom \n");
     scanf("%s",newnom);//gestion d'err si newnom vide 
     strcpy(tabEtudient[numetud-1].nom,newnom);


}
void modifierPrenom()
{
    char newprenom[20];
    int numetud;
   do{
        printf("Enter le numero de etudient que vous voulez modifier ses information : ");
        scanf("%d",&numetud);
        if(numetud<0 || numetud >id)
          printf("le numero d'etudient invalide . Essez de nouveau\n");
        
    }while(numetud<0 || numetud >id);

    printf("entrer le nouveau prenom \n");
     scanf("%s",newprenom);//gestion d'err si newnom vide 
     strcpy(tabEtudient[numetud-1].nom,newprenom);


}

void modifierdepartement()
{
    char newdep[20];
    int numetud;
   do{
        printf("Enter le numero de etudient que vous voulez modifier ses information : ");
        scanf("%d",&numetud);
        if(numetud<0 || numetud >id)
          printf("le numero d'etudient invalide . Essez de nouveau\n");
        
    }while(numetud<0 || numetud >id);

    printf("entrer le nouveau prenom \n");
     scanf("%s",newdep);//gestion d'err si newnom vide 
     strcpy(tabEtudient[numetud-1].nom,newdep);
        afficher();
    

}


void modifier()
{
    int choix;
    printf("******************************modifier************************\n");
    printf("pour modifier le nom Taper 1 \n");
    printf("pour modifier prenom Taper 2 \n");
    printf("pour modifier departement Taper 3 \n");
    printf("pour modifier la note Taper 4 \n");
    printf(" Pour modifier la date de naissance Taper 5 \n ");
    printf("pour rettour taper 0 \n");
    scanf("%d",&choix);

    switch (choix)
    {
    case 1:
        modifierNom();
        modifier();
    case 2:
       modifierPrenom();
       modifier();
    case 3 :
       modifierdepartement();
       modifier();
    
    case 0:
       break;
    }
    
}

void menu()
{
    int choix;
    printf("pour Ajouter un Etudient Taper 1 \n");
    printf("pour modifier un Etudient Taper 2 \n");
    printf("pour supprimer un Etudient Taper 3 \n");
    printf("pour afficher un Etudient Taper 4 \n");
    printf(" Pour Calculer le moyenne globle pour chaque departement Taper 5 \n ");
    printf("pour rechercher sue un etudient taper 6\n");
    printf("pour trier  taper 7 \n");
    printf("pour quitter taper 0 \n");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
         ajouter();
        /* code */
        menu();
    case 2:
      modifier();
    case 4:
        afficher();
        menu();
    case 0:
        break;
    }
} 


int main()
{
    // Example data to demonstrate display
    strcpy(tabEtudient[0].nom, "kaoutar");
    strcpy(tabEtudient[0].prenom, "laajil");
    strcpy(tabEtudient[0].departement, "Informatique");
    tabEtudient[0].numEtudient = ++id;
    tabEtudient[0].dateNaissance.jour = 8;
    tabEtudient[0].dateNaissance.mois = 9;
    tabEtudient[0].dateNaissance.annee = 2001;
    tabEtudient[0].note = 12.50;

   menu();

    return 0;
}
