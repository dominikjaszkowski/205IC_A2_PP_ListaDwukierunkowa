struct listadwukierunkowa{
    int wartosc;
    struct listadwukierunkowa* next;
    struct listadwukierunkowa* prev;
};


void pokazliste(struct listadwukierunkowa* ogon){
    struct listadwukierunkowa* nowy = ogon;
    while (nowy != NULL){
        printf("%d ", nowy->wartosc);
        nowy = nowy->next;
    }
    printf("\n");
}

struct listadwukierunkowa* dodajNaPoczatku(struct listadwukierunkowa* glowa, int value){
    struct listadwukierunkowa * nowyElement = (struct listadwukierunkowa*) malloc(sizeof(struct listadwukierunkowa));
    nowyElement->wartosc = value;
    nowyElement->next = NULL;
    nowyElement->prev = nowyElement;

    if( glowa == NULL){
        glowa = nowyElement;
    }else{
        nowyElement->next = glowa;
    }

    return nowyElement;
}

struct listadwukierunkowa* dodajNaKoniec(struct listadwukierunkowa* ogon, int value){
    struct listadwukierunkowa * nowyElement = (struct listadwukierunkowa *)malloc(sizeof(struct listadwukierunkowa));
    nowyElement->next = NULL;
    nowyElement->wartosc = value;
    nowyElement->prev = nowyElement;
    if (ogon == NULL){
        ogon = nowyElement;
    }
    else{
        struct listadwukierunkowa* nowy = ogon;
        while (nowy->next != NULL){
            nowy = nowy->next;
        }
        nowy->next = nowyElement;
    }
    return ogon;
}
struct listadwukierunkowa* usun(struct listadwukierunkowa* glowa, int value){
    struct listadwukierunkowa * nowy = glowa;
    while(nowy->next->wartosc != value){
        nowy = nowy->next;

    }
    struct listadwukierunkowa* usuniecie = nowy->next;
    nowy->next = usuniecie->next;
    free(usuniecie);

    return glowa;
}

int  wczytajLiczbe(char* tresc){
    int liczba;
    printf("%s",tresc);
    scanf("%d",&liczba);

    return liczba;
}
int Menu(){
    int opcja;

    printf("Co chcesz wykonac: \n");
    printf("1) Wypisz liste\n");
    printf("2) Dodaj element na poczatek listy\n");
    printf("3) Dodaj element na koniec listy\n");
    printf("4) Usun z listy\n");
    printf("5) Zakoncz program\n");
    printf("Moja opcja: ");
    scanf("%d",&opcja);
    printf("\n");
    return opcja;
}