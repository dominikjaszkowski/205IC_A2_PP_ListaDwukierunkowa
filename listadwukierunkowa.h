struct element {
    int value;
    struct element *next;
    struct element *prev;
} *glowa, *ogon;

void dodajnakonieclisty(int wartosc);

void dodajnapoczateklisty(int wartosc);

void dodajdosrodka(int wartosc);

void usunzlisty();

void wypiszodpoczatku();

void wypiszodkonca();



void dodajnakonieclisty(int wartosc) {
    struct element *nowyelement = (struct element *) malloc(sizeof(struct element));

    nowyelement->value = wartosc;
    nowyelement->next = NULL;
    nowyelement->prev = NULL;

    if (glowa == NULL) {
        glowa = nowyelement;
        ogon = glowa;
    } else {
        nowyelement->prev = ogon;
        ogon->next = nowyelement;
        ogon = nowyelement;
    }

}

void dodajnapoczateklisty(int wartosc) {
    struct element *nowyelement = (struct element *) malloc(sizeof(struct element));

    nowyelement->value = wartosc;
    nowyelement->next = NULL;
    nowyelement->prev = NULL;

    if (glowa == NULL) {
        ogon = nowyelement;
        glowa = ogon;
    } else {
        nowyelement->prev = ogon;
        ogon->next = nowyelement;
        ogon = nowyelement;
    }

}

void dodajdosrodka(int wartosc) {
    struct element *nowyelement = (struct element *) malloc(sizeof(struct element));
    int ilosc;
    nowyelement->value = wartosc;
    struct element *srodek = glowa;
    for (int i = 0, wylicz = ilosc / 2 - 1; i < wylicz; i++) {
        srodek = srodek->next;
        nowyelement->prev = srodek->prev;
        nowyelement->next = srodek->next;
        srodek->next = nowyelement;
    }
}


void wypiszodpoczatku() {
    struct element *iterator = glowa;
    while (iterator != NULL) {
        printf("%i ", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}

void wypiszodkonca() {
    struct element *iterator = ogon;
    while (iterator != NULL) {
        printf("%i ", iterator->value);
        iterator = iterator->prev;
    }
    printf("\n");
}

void usunzlisty() {
    if (ogon->prev != NULL) {
        struct element *prev = ogon->prev;
        free(ogon);
        ogon = prev;
        ogon->next = NULL;
    }
}