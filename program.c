#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Les scores sont déclarés ici (en dehors du main) pour que
// la procédure afficher_bilan puisse les lire sans paramètre.
int scoreJoueur = 0;
int scoreOrdi = 0;

// Étape 2 : procédure sans paramètre
void afficher_bilan()
{
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous : %d | Ordi : %d\n", scoreJoueur, scoreOrdi);
    if (scoreJoueur > scoreOrdi)
    {
        printf("Bravo, vous avez gagné la partie !\n");
    }
    else if (scoreOrdi > scoreJoueur)
    {
        printf("L'ordinateur remporte la partie...\n");
    }
    else
    {
        printf("Match nul parfait !\n");
    }
}

// Étape 3 : procédure avec un paramètre
// Affiche le nom du choix qui correspond au nombre reçu.
void afficher_choix(int choix)
{
    if (choix == 1)
    {
        printf("Pierre");
    }
    else if (choix == 2)
    {
        printf("Feuille");
    }
    else if (choix == 3)
    {
        printf("Ciseaux");
    }
    else if (choix == 4)
    {
        printf("Lézard");
    }
    else
    {
        printf("Spock");
    }
}

int main()
{
    int manche = 1;
    int choixJoueur;
    int choixOrdi;

    printf("=== PIERRE, FEUILLE, CISEAUX, LEZARD, SPOCK (7 Manches / avantage décisif de 2) ===\n");

    while (manche <= 7
        && scoreJoueur-scoreOrdi < 2
        && scoreOrdi-scoreJoueur < 2)
    {
        printf("--- Manche %d/7 ---\n", manche);

        // Saisie du joueur
        bool incorrect;
        do
        {
            // Menu affiché avec une boucle for de 1 à 5
            printf("Choix :\n");
            for (int i = 1; i <= 5; i = i + 1)
            {
                printf("%d = ", i);
                afficher_choix(i);
                printf("\n");
            }
            scanf("%d", &choixJoueur);
            incorrect = choixJoueur < 1 || 5 < choixJoueur;
            if(incorrect) {
                printf("Non valide, valeurs de 1 à 5 acceptées\n");
            }
        } while (incorrect);

        // Choix aléatoire de l'ordinateur (1, 2, 3, 4 ou 5)
        choixOrdi = (rand() % 5) + 1;
        printf("L'ordinateur a choisi : ");
        afficher_choix(choixOrdi);
        printf("\n");

        // Détermination du gagnant de la manche
        if (choixJoueur == choixOrdi)
        {
            printf("Égalité !\n");
        }
        else if ((choixJoueur == 1 && (choixOrdi == 3 || choixOrdi == 4)) ||
                 (choixJoueur == 2 && (choixOrdi == 1 || choixOrdi == 5)) ||
                 (choixJoueur == 3 && (choixOrdi == 2 || choixOrdi == 4)) ||
                 (choixJoueur == 4 && (choixOrdi == 2 || choixOrdi == 5)) ||
                 (choixJoueur == 5 && (choixOrdi == 1 || choixOrdi == 3)))
        {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur = scoreJoueur + 1;
        }
        else
        {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi = scoreOrdi + 1;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);
        manche = manche + 1;
    }

    afficher_bilan();

    return 0;
}