#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char nom[25][25];
    int num_de_tele[25];
    char email[25][25];
};

int main()
{
    struct Contact contact;

    int Nombre_de_contact = 0;
    int option;
    char restart = 'y';

    while (restart == 'y' || restart == 'Y')
    {
        system("cls");

        printf("\n\n");
        printf("------|   Gestion de Contacts   |-----");
        printf("\n\n\t|1|-> Ajouter un contact");
        printf("\n\n\t|2|-> Afficher tout les contact");
        printf("\n\n\t|3|-> Rechercher un Contact");
        printf("\n\n\t|4|-> Modifier un contact");
        printf("\n\n\t|5|-> Supprimer un contact");
        printf("\n\n\t|6|-> Quitte");
        printf("\n\n\t=> Choisissez une option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            system("cls");
            printf("\n\n");
            printf("------|   Ajouter un Contacts   |-----");
            printf("\n\n");

            printf("\nDonner %d nom : ", Nombre_de_contact + 1);
            scanf("%s", &contact.nom[Nombre_de_contact]);

            printf("\nDonner %d Numero de tetephone : ", Nombre_de_contact + 1);
            scanf("%d", &contact.num_de_tele[Nombre_de_contact]);

            printf("\nDonner %d email address : ", Nombre_de_contact + 1);
            scanf("%s", &contact.email[Nombre_de_contact]);

            Nombre_de_contact++;

            printf("\n\n\t->Contact ajouter !");
        }
        break;
        case 2:
        {
            system("cls");
            printf("\n\n");
            printf("------|   Afficher tout Contacts   |-----");
            printf("\n\n");

            for (int i = 0; i < Nombre_de_contact; i++)
            {
                printf("\n\n====Contact | %d |==========", i + 1);
                printf("\n\n==>Nom -->  %s", contact.nom[i]);
                printf("\n\n==>Tele -->  %d", contact.num_de_tele[i]);
                printf("\n\n==>Email -->  %s", contact.email[i]);
                printf("\n\n===========================\n");
            }
        }
        break;
        case 3:
        {
            system("cls");
            printf("\n\n");
            printf("------|   Rechercher un Contact   |-----");
            printf("\n\n");

            int found = 0;
            char temporaire_nom[25];
            printf("\n\nDonner le nom de contact a rechercher : ");
            scanf("%s", &temporaire_nom);

            for (int i = 0; i < Nombre_de_contact; i++)
            {

                if (strcmp(temporaire_nom, contact.nom[i]) == 0)
                {
                    printf("\n\n====Contact | %d |==========", i + 1);
                    printf("\n\n==>Nom -->  %s", contact.nom[i]);
                    printf("\n\n==>Tele -->  %d", contact.num_de_tele[i]);
                    printf("\n\n==>Email -->  %s", contact.email[i]);
                    printf("\n\n===========================\n");

                    found = 1;
                    break;
                }
            }

            if (found != 1)
            {
                printf("\n\n->Le Contact est indesponible");
            }
        }
        break;
        case 4:
        {
            system("cls");
            printf("\n\n");
            printf("------|   Modifier un Contact   |-----");
            printf("\n\n");

            int found = 0;
            char temporaire_nom[25];

            int new_tele_num;
            char new_address[25];

            printf("\n\nDonner le nom de contact a rechercher : ");
            scanf("%s", &temporaire_nom);

            for (int i = 0; i < Nombre_de_contact; i++)
            {
                if (strcmp(temporaire_nom, contact.nom[i]) == 0)
                {
                    printf("\n\nDonner nouveau telephone number : ");
                    scanf("%d", &new_tele_num);

                    printf("\n\nDonner nouveau Address : ");
                    scanf("%s", &new_address);

                    strcpy(contact.email[i], new_address);
                    contact.num_de_tele[i] = new_tele_num;

                    found = 1;
                    printf("\n\n\t->Contact Modifier !");
                    break;
                }
            }

            if (found != 1)
            {
                printf("\n\n->Le Contact est indesponible");
            }
        }
        break;
        case 5:
        {
            system("cls");
            printf("\n\n");
            printf("------|   Supprimer un Contact   |-----");
            printf("\n\n");

            int found = 0;
            char temporaire_nom[25];

            printf("\n\nDonner le nom de contact a rechercher : ");
            scanf("%s", &temporaire_nom);

            for (int i = 0; i < Nombre_de_contact; i++)
            {
                if (strcmp(temporaire_nom, contact.nom[i]) == 0)
                {
                    for (int j = i; j < Nombre_de_contact - 1; j++)
                    {
                        strcpy(contact.nom[j], contact.nom[j + 1]);
                        strcpy(contact.email[j], contact.email[j + 1]);
                        contact.num_de_tele[j] = contact.num_de_tele[j + 1];
                    }

                    found = 1;
                    Nombre_de_contact--;

                    printf("\n\n\t->Contact Supprimer !");
                    break;
                }
            }

            if (found != 1)
            {
                printf("\n\n->Le Contact est indesponible");
            }
        }
        break;
        case 6:
            printf("\n\n");
            printf("Tu Quitte le Programme");
            exit(0);
            break;
        }

        // scanf("%c");
        printf("\n\n\n->Continuer ? (y) / (n) : ");
        scanf(" %c", &restart);
    }

    return 0;
}
