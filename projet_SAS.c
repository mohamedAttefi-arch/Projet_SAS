// Online C compiler to run C program online
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char post[4][50] = { "gardien", "defenseur", "milieu", "attaquant"};
struct Joueur{
    char nom[50];
    char prenom[50];
    char post[20];
    int id_joueur;
    int age;
    int numero_maillot;
    int but;
};
int  cpt = 0;
int joueur_a_ajouter;
struct Joueur j[50];
int ID = 0;
char joueur_a_chercher[50];


void ajouter (struct Joueur j[])
{
    int ajout;
    int choix_poste;
    printf("1. pour ajouter un joueur\n");
    printf("2. pour ajouter plusieurs joueurs\n");
    printf("votre choix: \n");
    scanf("%d", &ajout);
    getchar();
    switch (ajout)
    {
    case 1:
        joueur_a_ajouter = 1;
        printf("entrez les information du joueur a ajouter:\n");
        printf("Nom: ");
        scanf("%s", j[cpt].nom);
        printf("Prenom: ");
        scanf("%s", j[cpt].prenom);
        printf("Age: ");
        scanf("%d", &j[cpt].age);
        printf("Numero de maillot: ");
        scanf("%d", &j[cpt].numero_maillot);
        printf("Nombre de buts: ");
        scanf("%d", &j[cpt].but);
        printf("Choisissez le poste :\n");
        for (int i = 0; i < 4; i++) {
            printf("%d. %s\n", i + 1, post[i]);
        }
        printf("Votre choix (1-4): ");
        scanf("%d", &choix_poste);
        if (choix_poste < 1 || choix_poste > 4) {
            printf("Choix invalide.\n");
            return;
        }
        strcpy(j[cpt].post, post[choix_poste - 1]);
        j[cpt].id_joueur = ID + 1;
        break;
    case 2:
        printf("Combien des joueur voulez-vous ajouter? ");
    scanf("%d", &joueur_a_ajouter);
    getchar();
    for(int i = 0; i < cpt + joueur_a_ajouter; i++)
    {
        printf("Joueur %d\n", i+1);
        printf("Nom: ");
        scanf("%s", &j[i].nom);
        for (int i = 0; j[i].nom[i] != '\0'; i++) 
        {
            j[i].nom[i] = toupper(j[i].nom[i]);
        }
        printf("Prenom: ");
        scanf("%s", &j[i].prenom);
        for (int i = 0; j[i].prenom[i] != '\0'; i++) 
        {
            j[i].prenom[i] = toupper(j[i].prenom[i]);
        }
        printf("Age: ");
        scanf("%d", &j[i].age);
        printf("Numero de maillot: ");
        scanf("%d", &j[i].numero_maillot);
        printf("les buts: ");
        scanf("%d", &j[i].but);
        getchar();
    
        printf("Choisissez le poste :\n");
        for (int i = 0; i < 4; i++) {
            printf("%d. %s\n", i + 1, post[i]);
        }   

        printf("Votre choix (1-4): ");
        scanf("%d", &choix_poste);

    
        if (choix_poste < 1 || choix_poste > 4) 
        {
            printf("Choix invalide.\n");
            return;
        }
            strcpy(j[i].post, post[choix_poste - 1]);
            printf("Le joueur %s %s joue comme %s, son numero de maillot est %d et il a marqué %d des buts\n", j[i].nom, j[i].prenom, j[i].post, j[i].numero_maillot, j[i].but);
            j[i].id_joueur = ID+1;
            printf("ID du joueur: %d\n", j[i].id_joueur);
            ID++;
    }
    
    default:
        break;
    }
    cpt+=joueur_a_ajouter;

    printf("joueur ajoute avec succes!\n");
}
int proposition_de_ajout(struct Joueur j[])
{
    int choix_de_recherche;
    if (cpt == 0)
    {
        printf("ajouter d'abord des joueur\n");
        printf("voulez vous ajouter des joueur?\n ");
        printf("1.pour ajouter\n");
        printf("2.pour retourner au menu principale\n");
        printf("votre choix: \n");
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
struct Joueur rechercher (struct Joueur j[])
{
    proposition_de_ajout(j);
    
    if (cpt > 0)
    {

        int found = 0;
        printf("rechercher un joueur\n");
        printf("1. Par nom\n");
        printf("2. Par ID\n");
        printf("0.pour revenir au menu principal\n");
        int choix;
        printf("Votre choix: ");
        scanf("%d", &choix);
        getchar();
            switch(choix)
        {
            case 1:
                printf("Entrez le nom du joueur: ");
                scanf("%s", &joueur_a_chercher[50]);
                for(int i = 0; i < cpt; i++)
                {
                    if(strcmp(j[i].nom, joueur_a_chercher) == 0)
                    {
                        return j[i];
                        found = 1;
                        break;
                    }
                }
                if(!found)
                {
                    printf("Joueur non trouve.\n");
                }
                break;
            case 2:
                int id_a_chercher;
                printf("Entrez l'ID du joueur: ");
                scanf("%d", &id_a_chercher);
                for(int i = 0; i < cpt; i++)
                {
                    if(j[i].id_joueur == id_a_chercher)
                    {
                        return j[i];
                        found = 1;
                        printf("joueur trouve");
                        break;
                    }
                }
                if(!found)
                {
                    printf("Joueur non trouve.\n");
                }
                break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
                
            default:
                printf("Choix invalide.\n");
        }
        
    }
    
    
    

}
void modifier(struct Joueur j[])
{
    rechercher(j);
    if (1 && cpt > 0) 
    {
        printf("1. Modifier le poste\n");
        printf("2. Modifier l'age\n");
        printf("3. Modifier le numero de maillot\n");
        printf("4. Modifier les buts\n");
        printf("0. Retour au menu principal\n");
        int choix_modif;
        printf("Votre choix: ");
        scanf("%d", &choix_modif);
        getchar();
        do
        {
            switch(choix_modif)
            {
                case 1:
                    for (int i = 0; i < cpt; i++)
                    {
                        printf("le poste actuel est: %s\n", j[i].post);
                        int choix_poste;
                        printf("Choisissez le nouveau poste :\n");
                        for (int i = 0; i < 4; i++) {
                            printf("%d. %s\n", i + 1, post[i]);
                        }   
                        printf("Votre choix (1-4): ");
                        scanf("%d", &choix_poste);
                        if (choix_poste < 1 || choix_poste > 4) {
                            printf("Choix invalide.\n");
                            return;
                        }
                        strcpy(j[i].post, post[choix_poste - 1]);
                        printf("Poste modifie avec succes!\n");
                    }
                    break;
                case 2:
                    for (int i = 0; i < cpt; i++)
                    {
                        printf("l'age actuel est: %s\n", j[i].age);
                        printf("Nouveau age: ");
                        scanf("%s", &j[i].age);
                        printf("l'age modifie avec succes!\n");
                    }
                    break;
                case 3:
                    for (int i = 0; i < cpt; i++)
                    {
                        printf("le numero de maillot actuel est: %s\n", j[i].numero_maillot);
                        printf("Nouveau numero: ");
                        scanf("%s", &j[i].numero_maillot);
                        printf("le numero modifie avec succes!\n");
                    }
                case 4:
                    for (int i = 0; i < cpt; i++)
                    {
                        printf("les buts actuel sont: %s\n", j[i].but);
                        printf("Nouveau numero: ");
                        scanf("%s", &j[i].but);
                        printf("les but modifie avec succes!\n");
                    }
                    break;
                case 0:
                    printf("Retour au menu principal.\n");
                    break;

            } 
        
                

        
        }while (choix_modif != 0);
    } 
    else if (0)
    {
        printf("joueur introvable");
    }
    
   
}
void supprimer(struct Joueur j[])
{
    rechercher(j);
    if (1)
    {
            for (int i = 0; i < cpt; i++)
        {
            
                for (int K = i; K < cpt - 1; K++)
                {
                    j[K] = j[K + 1];
                }
                cpt--;
                printf("\nle joueur est suprimmer\n");
            
        }
        
    
    }
    else if (0)
    {
        printf("joueur introuvable\n");
    }
    
    
    
    
}
void afficher(struct Joueur j[])
{
    proposition_de_ajout(j);
    if (cpt > 0)
    {
        printf("1. pour un ordre selon age\n");
        printf("2. pour un ordre selon numero de maillot\n");
        printf("3. pour un ordre selon le nom\n");
        printf("4. pour un ordre selon le poste\n");
        printf("5. pour un ordre selon l'ID\n");
        printf("6. pour afficher tous les joueurs\n");
        printf("0. pour revenir au menu principal\n");
        int choix_affichage;
        printf("Votre choix: ");
        scanf("%d", &choix_affichage);
        getchar();
        
            switch(choix_affichage)
            {
                case 1:
                    for(int i = 0; i < cpt-1; i++)
                    {
                        for(int k = i+1; k < cpt; k++)
                        {
                            if(j[i].age > j[k].age)
                            {
                                struct Joueur temp = j[i];
                                j[i] = j[k];
                                j[k] = temp;
                            }
                        }
                    }
                    printf("Joueurs par age:\n");
                    for(int i = 0; i < cpt; i++)
                    {
                        printf("le nom: %s %s || Poste: %s || Age: %d || Numero de maillot: %d || ID: %d\n", j[i].nom, j[i].prenom, j[i].post, j[i].age, j[i].numero_maillot, j[i].id_joueur);
                    }
                    break;
                case 2:
                    for(int i = 0; i < cpt-1; i++)
                    {
                        for(int k = i+1; k < cpt; k++)
                        {
                            if(j[i].numero_maillot > j[k].numero_maillot)
                            {
                                struct Joueur temp = j[i];
                                j[i] = j[k];
                                j[k] = temp;
                            }
                        }
                    }
                    printf("par numero de maillot:\n");
                    for(int i = 0; i < cpt; i++)
                    {
                        printf("le nom: %s %s || Poste: %s || Age: %d || Numero de maillot: %d || ID: %d\n", j[i].nom, j[i].prenom, j[i].post, j[i].age, j[i].numero_maillot, j[i].id_joueur);
                    }
                    break;
                case 3:
                    
                    for(int i = 0; i < cpt-1; i++)
                    {
                        for(int k = i+1; k < cpt; k++)
                        {
                            if(strcmp(j[i].nom, j[k].nom) > 0)
                            {
                                struct Joueur temp = j[i];
                                j[i] = j[k];
                                j[k] = temp;
                            }
                        }
                    }
                    printf("Joueur par nom:\n");
                    for(int i = 0; i < cpt; i++)
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
                        printf("Choix invalide.\n");
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
                        for(int i = 0; i < cpt-1; i++)
                        {
                            for(int k = i+1; k < cpt; k++)
                            {
                                if(j[i].id_joueur > j[k].id_joueur)
                                {
                                    struct Joueur temp = j[i];
                                    j[i] = j[k];
                                    j[k] = temp;
                                }
                            }
                        }
                        printf("Joueurs par ID:\n");
                        for(int i = 0; i < cpt; i++)
                        {
                            printf("%s %s || Poste: %s || Age: %d || Numero de maillot: %d || ID: %d\n", j[i].nom, j[i].prenom, j[i].post, j[i].age, j[i].numero_maillot, j[i].id_joueur);
                        }
                        break;
                    case 6:
                        for (int i = 0; i < cpt; i++)
                        printf("Nom: %s %s || ID: %d || les buts: %d || numero de maillot: %d\n", j[i].nom, j[i].prenom, j[i].id_joueur, j[i].but, j[i].numero_maillot);
                    case 0:
                        return;
                    default:
                    printf("Choix invalide.\n");
                    break;
                    
         }
    }
}
   
    
    
 
void statistique(struct Joueur j[])
{
    proposition_de_ajout(j);
    printf("1. Afficher le nombre total de joueurs dans l'équipe.\n");
    printf("2. Afficher l'âge moyen des joueurs.\n");
    printf("3. Afficher les joueurs ayant marqué plus de X buts.\n");
    printf("4. Afficher le meilleur buteur.\n");
    printf("5. Afficher le joueur le plus jeune et le plus âgé.\n");
    printf("0. pour retourner au menu principale\n");
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
            int somme_dage;
            for (int i = 0; i < cpt; i++)
            {
                somme_dage = j[i].age + j[i+1].age;
            }
            age_moyen = somme_dage/cpt;
            printf("l'age moyen des joueur est: %d\n", age_moyen);
            break;
        case 3:
            int X;
            printf("entrez le nombre des but: \n");
            scanf("%d", &X);
            getchar();
            for (int i = 0; i < cpt; i++)
            {
                if (j[i].but >= X)
                {
                    printf("voici les joueur qui ont marqué plus de %d buts: \n", X);
                    for (int i = 0; i < cpt; i++)
                    {
                        printf("%s %s", j[i].nom, j[i].prenom);
                    }
                    
                }
                else
                {
                    printf("aucun joueur a marqué %d ou plus de %d buts\n", X, X);
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
            printf("il a marqué %d\n", max);
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
            printf("le joueur le plus agé est: \n");
            printf("%s\n", majeur);
            printf("il a %d ans\n", max_age);
            break;
            case 6:
            for (int i = 0; i < cpt; i++)
            {
                printf("Nom: %s %s || ID: %d || les buts: %d || numero de maillot: %d\n", j[i].nom, j[i].prenom, j[i].id_joueur, j[i].but, j[i].numero_maillot);
            }
            break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
            default:
            printf("choix invalide\n");
            break;
    }
}

void menu()
{
    int choix;
    do
    {  
        printf("\t--------MENU--------\n");
        printf("\t1. Ajouter un joueur\n");
        printf("\t2. Rechercher un joueur\n");
        printf("\t3. Modifier un joueur\n");
        printf("\t4. Supprimer un joueur\n");
        printf("\t5. Afficher les joueur\n");
        printf("\t6. afficher les statistiques\n");
        printf("\t0. Quitter\n");
        printf("Votre choix: \n");
        scanf("%d", &choix);
        switch(choix)
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
                printf("Choix invalide! Veuillez reessayer.");
                break;
        }
    } while(choix != 0);
}
int main()
{
    
    menu();
    return 0;
}
