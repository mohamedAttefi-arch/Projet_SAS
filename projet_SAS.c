#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

char post[4][50] = {"gardien", "defenseur", "milieu", "attaquant"};
int ID = 11;
int cpt = 10;
int joueur_a_ajouter;
struct Joueur
{
    char nom[50];
    char prenom[50];
    char post[20];
    int id_joueur;
    int age;
    int numero_maillot;
    int but;
};
struct Joueur j[50] = {
    {"Ronaldo", "Cristiano", "attaquant", 1, 38, 7, 1200},
    {"Messi", "Lionel", "attaquant", 2, 36, 10, 1300},
    {"Neymar", "Junior", "attaquant", 3, 31, 11, 500},
    {"Mbappe", "Kylian", "attaquant", 4, 24, 7, 250},
    {"Modric", "Luka", "milieu", 5, 37, 10, 90},
    {"Kante", "N'Golo", "milieu", 6, 31, 7, 30},
    {"Salah", "Mohamed", "attaquant", 7, 29, 11, 150},
    {"Ramos", "Sergio", "defenseur", 8, 35, 4, 100},
    {"Alisson", "Becker", "gardien", 9, 29, 1, 0},
    {"Lewandowski", "Robert", "attaquant", 10, 33, 9, 500}};
void ajouter(struct Joueur j[])
{
    int k = 0;
    int nb_exist;
    int choix_poste;
    printf("Combien des joueur voulez-vous ajouter? ");
    scanf("%d", &joueur_a_ajouter);
    getchar();
    for (int i = cpt; i < cpt + joueur_a_ajouter; i++)
    {
        printf("Joueur %d\n", i + 1);
        printf("Nom: ");
        scanf("%s", &j[i].nom);

        printf("Prenom: ");
        scanf("%s", &j[i].prenom);

        printf("Age: ");
        scanf("%d", &j[i].age);

        printf("Numero de maillot: ");
        scanf("%d", &j[i].numero_maillot);

        printf("les buts: ");
        scanf("%d", &j[i].but);
        getchar();

        printf("Choisissez le poste :\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d. %s\n", i + 1, post[i]);
        }

        printf("Votre choix (1-4): ");
        scanf("%d", &choix_poste);

        if (choix_poste < 1 || choix_poste > 4)
        {
            printf(ANSI_COLOR_RED "\nChoix invalide.\n" ANSI_COLOR_RESET);
            return;
        }
        strcpy(j[i].post, post[choix_poste - 1]);

        j[i].id_joueur = ID;
        printf("ID du joueur: %d\n", j[i].id_joueur);
        ID++;
        time_t current_time;
        current_time = time(NULL);
        printf("date d'inscription: %s", ctime(&current_time));
    }
    cpt += joueur_a_ajouter;

    printf(ANSI_COLOR_GREEN "\njoueur ajoute avec succes!\n" ANSI_COLOR_RESET);
}
int proposition_de_ajout(struct Joueur j[])
{
    int choix_de_recherche;
    if (cpt == 0)
    {
        printf("\t_________________________________________________\n");
        printf("\t||            PROPOSITION D'AJOUT              ||\n");
        printf("\t||_____________________________________________||\n");
        printf("\t||         ajouter d'abord des joueur          ||\n");
        printf("\t||      voulez vous ajouter des joueur?        ||\n ");
        printf("\t||                                             ||\n");
        printf("\t||  1.pour ajouter                             ||\n");
        printf("\t||  2.pour retourner au menu principale        ||\n");
        printf("\t||_____________________________________________||\n");
        printf("\tvotre choix:\n");

        scanf("%d", &choix_de_recherche);
        getchar();
        switch (choix_de_recherche)
        {
        case 1:
            ajouter(j);
            break;
        case 2:
            break;
        }
    }
}
int rechercher(struct Joueur j[])
{
    proposition_de_ajout(j);

    if (cpt > 0)
    {

        int found = 0;
        char joueur_a_chercher[50];
        printf("\t____________________________________________\n");
        printf("\t||          RECHERCHER UN JOUEUR          ||\n");
        printf("\t||________________________________________||\n");
        printf("\t||  1. Par nom                            ||\n");
        printf("\t||  2. Par ID                             ||\n");
        printf("\t||  0.pour revenir au menu principal      ||\n");
        printf("\t||________________________________________||\n");
        int choix;
        printf("Votre choix: ");
        scanf("%d", &choix);
        getchar();
        switch (choix)
        {
        case 1:
            printf("Entrez le nom du joueur: ");
            scanf("%s", &joueur_a_chercher);
            getchar();
            for (int i = 0; i < cpt; i++)
            {
                if (strcmp(joueur_a_chercher, j[i].nom) == 0)
                {
                    printf(ANSI_COLOR_GREEN "\njoueur trouve: \n" ANSI_COLOR_RESET "%s %s || age: %d|| ID :%d || numero de maillot: %d || le post: %s || nombre des buts: %d \n", j[i].nom, j[i].prenom, j[i].age, j[i].id_joueur, j[i].numero_maillot, j[i].post, j[i].but);
                    found = 1;
                    return i;
                }
            }
            if (!found)
            {
                printf(ANSI_COLOR_RED "\nJoueur non trouve.\n" ANSI_COLOR_RESET);
                return -1;
            }
            break;
        case 2:
            int id_a_chercher;
            printf("Entrez l'ID du joueur: ");
            scanf("%d", &id_a_chercher);
            getchar();
            for (int i = 0; i < cpt; i++)
            {
                if (id_a_chercher == j[i].id_joueur)
                {
                    printf(ANSI_COLOR_GREEN "\njoueur trouve: \n" ANSI_COLOR_RESET "%s %s || age: %d|| ID :%d || numero de maillot: %d || le post: %s || nombre des buts: %d \n", j[i].nom, j[i].prenom, j[i].age, j[i].id_joueur, j[i].numero_maillot, j[i].post, j[i].but);
                    found = 1;
                    return i;
                }
            }
            if (!found)
            {
                printf(ANSI_COLOR_RED "\nJoueur non trouve.\n" ANSI_COLOR_RESET);
                return -1;
            }
            break;
        case 0:
            printf("Retour au menu principal.\n");
            break;

        default:
            printf(ANSI_COLOR_RED "\nChoix invalide.\n" ANSI_COLOR_RESET);
        }
    }
}
void modifier(struct Joueur j[])
{
    int found = 0;
    int indice_a_modifier = rechercher(j);
    int nv_indice;
    if (1 && indice_a_modifier > -1)
    {
        printf("\t__________________________________________________\n");
        printf("\t||             MENU DE MODIFICATION             ||\n");
        printf("\t||______________________________________________||\n");
        printf("\t||  1. Modifier le poste                        ||\n");
        printf("\t||  2. Modifier l'age                           ||\n");
        printf("\t||  3. Modifier le numero de maillot            ||\n");
        printf("\t||  4. Modifier les buts                        ||\n");
        printf("\t||  0. Retour au menu principal                 ||\n");
        printf("\t||______________________________________________||\n");
        int choix_modif;
        printf("Votre choix: ");
        scanf("%d", &choix_modif);
        getchar();
        switch (choix_modif)
        {
        case 1:
            printf("le poste actuel est: %s\n", j[indice_a_modifier].post);
            int choix_poste;
            printf("Choisissez le poste :\n");
            for (int i = 0; i < 4; i++)
            {
                printf("%d. %s\n", i + 1, post[i]);
            }

            printf("Votre choix (1-4): ");
            scanf("%d", &choix_poste);

            if (choix_poste < 1 || choix_poste > 4)
            {
                printf(ANSI_COLOR_RED "\nChoix invalide.\n" ANSI_COLOR_RESET);
                return;
            }
            strcpy(j[indice_a_modifier].post, post[choix_poste - 1]);
            printf(ANSI_COLOR_GREEN "\nle poste modifie avec succes!\n" ANSI_COLOR_RESET);
            break;
        case 2:

            printf("l'age actuel est: %d\n", j[indice_a_modifier].age);
            printf("Nouveau age: ");
            nv_indice = indice_a_modifier;
            scanf("%d", &j[nv_indice].age);
            printf(ANSI_COLOR_GREEN "\nl'age modifie avec succes!\n" ANSI_COLOR_RESET);
            break;
        case 3:
            printf("le numero de maillot actuel est: %d\n", j[indice_a_modifier].numero_maillot);
            printf("Nouveau numero: ");
            scanf("%d", &j[nv_indice].numero_maillot);
            printf(ANSI_COLOR_GREEN "\nle numero modifie avec succes!\n" ANSI_COLOR_RESET);
            break;
        case 4:
            printf("les buts actuel sont: %d\n", j[indice_a_modifier].but);
            printf("Nouveau numero: ");
            scanf("%d", &j[nv_indice].but);
            printf(ANSI_COLOR_GREEN "\nles but modifie avec succes!\n" ANSI_COLOR_RESET);
            break;
        case 0:
            printf("Retour au menu principal.\n");
            break;
        default:
            printf(ANSI_COLOR_RED "\nchoix invalide\n" ANSI_COLOR_RESET);
        }
    }
    else if (0)
    {
        printf(ANSI_COLOR_RED "\njoueur introvable\n" ANSI_COLOR_RESET);
    }
}
void supprimer(struct Joueur j[])
{
    int found = 0;
    int indice = rechercher(j);
    if (1)
    {
        for (int i = indice; i < cpt - 1; i++)
        {
            j[indice] = j[i + 1];
        }
        cpt--;
        printf(ANSI_COLOR_GREEN "\nle joueur est suprimmer\n" ANSI_COLOR_RESET);
    }
    else if (0)
    {
        printf(ANSI_COLOR_RED "\njoueur introuvable\n" ANSI_COLOR_RESET);
    }
}
void afficher(struct Joueur j[])
{
    proposition_de_ajout(j);
    if (cpt > 0)
    {
        printf("\t___________________________________________________\n");
        printf("\t||               MENU D'AFFICHAGE                ||\n");
        printf("\t||_______________________________________________||\n");
        printf("\t||   1. pour un ordre selon age                  ||\n");
        printf("\t||   2. pour un ordre selon numero de maillot    ||\n");
        printf("\t||   3. pour un ordre selon le nom               ||\n");
        printf("\t||   4. pour un ordre selon le poste             ||\n");
        printf("\t||   5. pour un ordre selon l'ID                 ||\n");
        printf("\t||   6. pour afficher tous les joueurs           ||\n");
        printf("\t||   0. pour revenir au menu principal           ||\n");
        printf("\t||_______________________________________________||\n");
        int choix_affichage;
        printf("Votre choix: ");
        scanf("%d", &choix_affichage);
        getchar();

        switch (choix_affichage)
        {
        case 1:
            struct Joueur temp;
            for (int i = 0; i < cpt - 1; i++)
            {
                for (int k = i + 1; k < cpt; k++)
                {
                    if (j[i].age > j[k].age)
                    {
                        temp = j[i];
                        j[i] = j[k];
                        j[k] = temp;
                    }
                }
            }
            printf("Joueurs par age:\n");
            for (int i = 0; i < cpt; i++)
            {
                printf("le nom: %s %s Poste: %s Age: %d  Numero de maillot: %d  ID: %d", j[i].nom, j[i].prenom, j[i].post, j[i].age, j[i].numero_maillot, j[i].id_joueur);
            }
            break;
        case 2:
            for (int i = 0; i < cpt - 1; i++)
            {
                for (int k = i + 1; k < cpt; k++)
                {
                    if (j[i].numero_maillot > j[k].numero_maillot)
                    {
                        temp = j[i];
                        j[i] = j[k];
                        j[k] = temp;
                    }
                }
            }
            printf("par numero de maillot:\n");
            for (int i = 0; i < cpt; i++)
            {
                printf("le nom: %s %s || Poste: %s || Age: %d || Numero de maillot: %d || ID: %d\n", j[i].nom, j[i].prenom, j[i].post, j[i].age, j[i].numero_maillot, j[i].id_joueur);
            }
            break;
        case 3:

            for (int i = 0; i < cpt - 1; i++)
            {
                for (int k = i + 1; k < cpt; k++)
                {
                    if (strcasecmp(j[i].nom, j[k].nom) > 0)
                    {
                        temp = j[i];
                        j[i] = j[k];
                        j[k] = temp;
                    }
                }
            }
            printf("Joueur par nom:\n");
            for (int i = 0; i < cpt; i++)
            {
                printf("%s %s || Poste: %s || Age: %d || Numero de maillot: %d || ID: %d\n", j[i].nom, j[i].prenom, j[i].post, j[i].age, j[i].numero_maillot, j[i].id_joueur);
            }
            break;
        case 4:
            int choix_poste;
            printf("Choisissez le poste :\n");
            for (int i = 0; i < 4; i++)
            {
                printf("%d. %s\n", i + 1, post[i]);
            }

            printf("Votre choix (1-4): ");
            scanf("%d", &choix_poste);
            getchar();
            if (choix_poste < 1 || choix_poste > 4)
            {
                printf(ANSI_COLOR_RED "\nChoix invalide.\n" ANSI_COLOR_RESET);
                return;
            }
            printf("voici les joueur qui ont ce post: \n");
            int found = 0;
            for (int i = 0; i < cpt; i++)
            {
                if (strcmp(j[i].post, post[choix_poste - 1]) == 0)
                {
                    printf("Nom: %s %s || ID: %d || les buts: %d || numero de maillot: %d\n", j[i].nom, j[i].prenom, j[i].id_joueur, j[i].but, j[i].numero_maillot);
                    found = 1;
                }
            }
            break;
        case 5:
            for (int i = 0; i < cpt - 1; i++)
            {
                for (int k = i + 1; k < cpt; k++)
                {
                    if (j[i].id_joueur > j[k].id_joueur)
                    {
                        temp = j[i];
                        j[i] = j[k];
                        j[k] = temp;
                    }
                }
            }
            printf("Joueurs par ID:\n");
            for (int i = 0; i < cpt; i++)
            {
                printf("%s %s || Poste: %s || Age: %d || Numero de maillot: %d || ID: %d\n", j[i].nom, j[i].prenom, j[i].post, j[i].age, j[i].numero_maillot, j[i].id_joueur);
            }
            break;
        case 0:
            return;
        default:
            printf(ANSI_COLOR_RED "\nChoix invalide.\n" ANSI_COLOR_RESET);
            break;
        }
    }
}
void statistique(struct Joueur j[])
{
    proposition_de_ajout(j);
    printf("\t_______________________________________________________________\n");
    printf("\t||                  MENU DES STATISTIQUES                    ||\n");
    printf("\t||___________________________________________________________||\n");
    printf("\t||   1. Afficher le nombre total de joueurs dans l'equipe.   ||\n");
    printf("\t||   2. Afficher l'age moyen des joueurs.                    ||\n");
    printf("\t||   3. Afficher les joueurs ayant marque plus de X buts.    ||\n");
    printf("\t||   4. Afficher le meilleur buteur.                         ||\n");
    printf("\t||   5. Afficher le joueur le plus jeune et le plus age.     ||\n");
    printf("\t||   0. pour retourner au menu principale.                   ||\n");
    printf("\t||___________________________________________________________||\n");
    int choix_statistique;
    printf("votre choix: \n");
    scanf("%d", &choix_statistique);
    switch (choix_statistique)
    {
    case 1:
        printf("vous avez %d joueurs", cpt);
        break;
    case 2:
        int age_moyen;
        int somme_dage = 0;
        for (int i = 0; i < cpt; i++)
        {
            somme_dage += j[i].age;
        }
        age_moyen = somme_dage / cpt;
        printf("l'age moyen des joueurs est: %d\n", age_moyen);
        break;
    case 3:
        int X;
        printf("entrez le nombre des but: \n");
        scanf("%d", &X);
        getchar();
        for (int i = 0; i < cpt; i++)
        {
            if (j[i].but > X)
            {
                printf("voici les joueur qui ont marque plus de %d buts: \n", X);
                for (int i = 0; i < cpt; i++)
                {
                    printf("%s %s", j[i].nom, j[i].prenom);
                }
            }
            else
            {
                printf("aucun joueur a marque plus de %d buts\n", X);
            }
        }
        break;
    case 4:
        int max = j[0].but;
        char meilleur[50];
        char separateur[] = " ";
        for (int i = 0; i < cpt; i++)
        {
            if (j[i].but >= j[0].but)
            {
                max = j[i].but;
                strcat(j[i].nom, separateur);
                strcpy(meilleur, strcat(j[i].nom, j[i].prenom));
            }
        }
        printf("votre meilleur joueur est: \n");
        printf("%s\n", meilleur);
        printf("il a marque %d\n", max);
        break;
    case 5:
        char mineur[50];
        char majeur[50];
        int max_age = j[0].age;
        int min_age = j[0].age;
        for (int i = 0; i < cpt; i++)
        {
            if (j[i].age <= j[0].age)
            {
                min_age = j[i].age;
                strcat(j[i].nom, separateur);
                strcpy(mineur, strcat(j[i].nom, j[i].prenom));
            }
        }
        printf("le joueur le plus jeune est: \n");
        printf("%s\n", mineur);
        printf("il a %d ans\n", min_age);

        for (int i = 0; i < cpt; i++)
        {
            if (j[i].age >= j[0].age)
            {
                max_age = j[i].age;
                strcat(j[i].nom, separateur);
                strcpy(majeur, strcat(j[i].nom, j[i].prenom));
            }
        }
        printf("le joueur le plus age est: \n");
        printf("%s\n", majeur);
        printf("il a %d ans\n", max_age);
        break;
    case 6:
        for (int i = 0; i < cpt; i++)
        {
            printf("Nom: %s %s      || ID: %d || les buts: %d || numero de maillot: %d\n", j[i].nom, j[i].prenom, j[i].id_joueur, j[i].but, j[i].numero_maillot);
        }
        break;
    case 0:
        printf("Retour au menu principal.\n");
        break;
    default:
        printf(ANSI_COLOR_RED "\nchoix invalide\n" ANSI_COLOR_RESET);
        break;
    }
}
void menu()
{
    int choix;
    do
    {
        printf("\t________________________________________\n");
        printf("\t||           MENU PRINCIPALE          ||\n");
        printf("\t||____________________________________||\n");
        printf("\t||  1. Ajouter un joueur              ||\n");
        printf("\t||  2. Rechercher un joueur           ||\n");
        printf("\t||  3. Modifier un joueur             ||\n");
        printf("\t||  4. Supprimer un joueur            ||\n");
        printf("\t||  5. Afficher les joueur            ||\n");
        printf("\t||  6. afficher les statistiques      ||\n");
        printf("\t||  0. Quitter                        ||\n");
        printf("\t||____________________________________||\n");
        printf("Votre choix: \n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            ajouter(j);
            break;
        case 2:
            rechercher(j);
            break;
        case 3:
            modifier(j);
            break;
        case 4:
            supprimer(j);
            break;
        case 5:
            afficher(j);
            break;
        case 6:
            statistique(j);
            break;
        case 0:
            printf("Au revoir!");
            break;
        default:
            printf(ANSI_COLOR_RED "\nChoix invalide! Veuillez reessayer.\n" ANSI_COLOR_RESET);
            break;
        }
    } while (choix != 0);
}
int main()
{
    menu();
    return 0;
}