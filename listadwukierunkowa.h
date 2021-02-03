struct element{
    int value;
    struct element* next;
    struct element* prev;
} *glowa, *ogon;

void dodajnakonieclisty(int wartosc);
void dodajnapoczateklisty(int wartosc);
void dodajdosrodka(int wartosc);
void usunzlisty();
void wypiszodpoczatku();
void wypiszodkonca();

int ilosc=0;


void dodajnakonieclisty(int wartosc){
    struct element* nowyelement = (struct element*) malloc(sizeof(struct element));

    nowyelement->value = wartosc;
    nowyelement->next = NULL;
    nowyelement->prev = NULL;

    if(glowa == NULL){
        glowa = nowyelement;
        ogon = glowa;
    }else{
        nowyelement->prev = ogon;
        ogon->next = nowyelement;
        ogon = nowyelement;
    }
    ilosc++;
}

void dodajnapoczateklisty(int wartosc){
    struct element* nowyelement = (struct element*) malloc(sizeof(struct element));

    nowyelement->value = wartosc;
    nowyelement->next = NULL;
    nowyelement->prev = NULL;

    if(glowa == NULL){
        ogon = nowyelement;
        glowa = ogon;
    }else{
        nowyelement->prev = ogon;
        ogon->next = nowyelement;
        ogon = nowyelement;
    }
    ilosc++;
}

void dodajdosrodka(int wartosc){
    struct element* nowyelement = (struct element*) malloc(sizeof(struct element));
    nowyelement->value=wartosc;
    struct element* srodkowyelement = glowa;
    for (int i = 0, end = ilosc / 2 - 1; i < end; i++){
        srodkowyelement = srodkowyelement->next;


        nowyelement->prev=srodkowyelement->prev;
        nowyelement->next=srodkowyelement->next;
        srodkowyelement->next = nowyelement;
    }
}




void wypiszodpoczatku(){
    struct element* iterator = glowa;
    while (iterator != NULL) {
        printf("%d ", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}

void wypiszodkonca() {
    struct element* iterator = ogon;
    while (iterator != NULL) {
        printf("%d ", iterator->value);
        iterator = iterator->prev;
    }
    printf("\n");
}

void usunzlisty(){
    if (ogon->prev != NULL)
    {
        struct element* prev = ogon->prev;
        free(ogon);
        ogon = prev;
        ogon->next = NULL;
    }
    ilosc--;
}