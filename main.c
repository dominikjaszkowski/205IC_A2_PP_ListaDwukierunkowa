#include <stdio.h>
#include <stdlib.h>
#include "ListaDwukierunkowa.h"

int Menu();
int wczytajLiczbe(char* tresc);

int main(){

    int wybor;
    struct listadwukierunkowa* ogon=NULL;
    struct listadwukierunkowa* glowa = NULL;

    while(wybor!=5){
        wybor=Menu();
        switch(wybor){
            case 1 :
                printf("Wypisana lista\n");
                pokazliste(glowa);
                printf("\n");
                break;
            case 2 :
                glowa = dodajNaPoczatku(glowa, wczytajLiczbe("Podaj liczbe do dodania na poczatek: \n"));
                break;
            case 3 :
                glowa = dodajNaKoniec(glowa, wczytajLiczbe("Podaj liczbe do dodania na koniec: \n"));
                break;
            case 4 :
                glowa = usun(glowa, wczytajLiczbe("Podaj element, ktory chcesz usunac: \n"));
                break;
            case 5 :
                printf("koniec programu");
                break;

        }
    }


}
