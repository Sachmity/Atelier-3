#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Définition des constantes
#define MANCHES_MAX 7
#define ECART_VICTOIRE 2

// Prototypes des fonctions
int demanderChoixJoueur(void);
void afficherNomChoix(int choix);
void afficherBilan(int scoreJoueur, int scoreOrdi);

int main(void)
{
    srand((unsigned int)time(NULL));

    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;

    printf("=== PIERRE, FEUILLE, CISEAUX, LEZARD, SPOCK (%d Manches / avantage decisif de %d) ===\n\n", 
           MANCHES_MAX, ECART_VICTOIRE);

    while (manche <= MANCHES_MAX && abs(scoreJoueur - scoreOrdi) < ECART_VICTOIRE)
    {
        printf("--- Manche %d/%d ---\n", manche, MANCHES_MAX);

        int choixJoueur = demanderChoixJoueur();

        // Choix aléatoire de l'ordinateur (1 à 5)
        int choixOrdi = (rand() % 5) + 1;
        printf("L'ordinateur a choisi : %d (", choixOrdi);
        afficherNomChoix(choixOrdi);
        printf(")\n");

        // Détermination du gagnant
        if (choixJoueur == choixOrdi)
        {
            printf("Egalite !\n");
        }
        else if ((choixJoueur == 1 && (choixOrdi == 3 || choixOrdi == 4)) ||
                 (choixJoueur == 2 && (choixOrdi == 1 || choixOrdi == 5)) ||
                 (choixJoueur == 3 && (choixOrdi == 2 || choixOrdi == 4)) ||
                 (choixJoueur == 4 && (choixOrdi == 2 || choixOrdi == 5)) ||
                 (choixJoueur == 5 && (choixOrdi == 1 || choixOrdi == 3)))
        {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur++;
        }
        else
        {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi++;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n", scoreJoueur, scoreOrdi);
        manche++;
    }

    afficherBilan(scoreJoueur, scoreOrdi);

    return 0;
}

// Fonction de saisie sécurisée du joueur
int demanderChoixJoueur(void)
{
    int choix;
    bool incorrect;

    do
    {
        printf("Choix (1 = Pierre, 2 = Feuille, 3 = Ciseaux, 4 = Lezard, 5 = Spock) : ");
        scanf("%d", &choix);

        incorrect = (choix < 1 || choix > 5);
        if (incorrect)
        {
            printf("Non valide, valeurs de 1 a 5 acceptees.\n");
        }
    } while (incorrect);

    return choix;
}

// Fonction pour afficher le nom correspondant au numéro du coup
void afficherNomChoix(int choix)
{
    const char *noms[] = {"", "Pierre", "Feuille", "Ciseaux", "Lezard", "Spock"};
    if (choix >= 1 && choix <= 5)
    {
        printf("%s", noms[choix]);
    }
}

// Fonction d'affichage du résultat final
void afficherBilan(int scoreJoueur, int scoreOrdi)
{
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous : %d | Ordi : %d\n", scoreJoueur, scoreOrdi);

    if (scoreJoueur > scoreOrdi)
    {
        printf("Bravo, vous avez gagne la partie !\n");
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