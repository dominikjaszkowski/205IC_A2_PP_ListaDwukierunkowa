#include <stdio.h>
#include <stdlib.h>
#include "listadwukierunkowa.h"


int main() {
    int opcja = -1;
    int ile;
    int srodek;


    while (opcja != 0) {
        printf("4. Usun liczby\n");
        printf("3. dodaj do srodka.\n");
        printf("2. Wypisanie od konca i usuniecie(pierw trzeba wykonac 1).\n");
        printf("1. dodanie liczb i wypisanie od poczatku.\n");
        printf("0. Zakonczyc program.\n");
        printf("Podaj liczbe: ");

        scanf("%i", &opcja);
        printf("\n");
        switch (opcja) {
            case 0:
                printf("koniec programu");
                break;

            case 1:
                printf("Podaj ile chcesz miec liczb: ");
                scanf("%i", &ile);
                printf("\n");
                for (int i = 1; i <= ile; i++) {
                    dodajnakonieclisty(i);
                    wypiszodpoczatku();

                }
                printf("\n");
                break;
            case 2:
                for (int i = ile - 1; i >= 0; i--) {
                    wypiszodkonca();
                    usunzlisty();
                }
                break;
            case 3:
                printf("Podaj liczbe do srodka: ");
                scanf("%i", &srodek);
                dodajdosrodka(srodek);
                printf("Liczba dodana\n");
                for (int i = ile; i >= 0; i--) {
                    usunzlisty();
                }
                break;

            case 4:
                for (int i = ile; i >= 0; i--) {
                    usunzlisty();
                }
                printf("Liczby usuniete\n");
                break;


            default:
                printf("Podaj wlasciwa opcje.\n");
                break;

        }
    }


}
