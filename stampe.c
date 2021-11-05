//
// Created by Giancarlo on 07/06/2021.
//

#include "stampe.h"

/** -------------funzioni per la stampa---------------*/
//mi permette di stampare caratteri ripetuti per l'intestazione
void stampaCaratteri(char ch,int n){
    while(n--)
    {
        putchar(ch);
    }
}

//Messaggio di Apertura
void benvenuto(){
    printf("\n\t");
    stampaCaratteri('=',70);
    printf("\n\t");
    stampaCaratteri('=',29);
    printf("[BENVENUTO]");
    stampaCaratteri('=',30);
    printf("\n\t");
    stampaCaratteri('=',33);
    printf("[in]");
    stampaCaratteri('=',33);
    printf("\n\t");
    stampaCaratteri('=',18);
    printf("[GESTIONE] [CRIMINALI] [PERICOLOSI]");
    stampaCaratteri('=',17);
    printf("\n\t");
    stampaCaratteri('=',70);
    printf("\n");
}
void intestazione(){

    printf("\n\n\t\t\t\t---------------------MENU---------------------");
    printf("\n\n\n\t\t\t\t\t\t%d. AGGIUNGI RECORD DETENUTO\n", INSERISCI_RECORD);
    printf("\t\t\t\t\t\t%d. GENERA RECORD CASUALMENTE\n", GENERA_CASUALMENTE_RECORD);
    printf("\t\t\t\t\t\t%d. ELIMINAZIONE RECORD DETENUTO\n",ELIMINAZIONE);
    printf("\t\t\t\t\t\t%d. RICERCA RECORD DETENUTO\n", RICERCA);
    printf("\t\t\t\t\t\t%d. CONFRONTO TRA DUE RECORD DETENUTO\n", CONFRONTO);
    printf("\t\t\t\t\t\t%d. ORDINAMENTO ALFABETICO DELL'ARCHIVIO\n",ORDINAMENTO_ALFABETICO);
    printf("\t\t\t\t\t\t%d. STAMPA DEL SINGOLO SOGGETTO\n",STAMP_RECORD_SINGOLO);
    printf("\t\t\t\t\t\t%d. STAMPA GENERALE \n",STAMPA_GENERALE);
    printf("\t\t\t\t\t\t%d. Esci\n", ESCI);
    printf("\t\t\t\t\t\t\tInserisci la tua scelta:  ");

}

void stampaSingoloDetenuto(VettoreDinamico *vd){
    int indice;
    printf("\nInserire indice del soggetto da stampare");
    scanf("%d", &indice);
    printf("\n");
    if(indice-1>= vd->nDetenuti){
        printf("\n\t*** Attanzione ***");
        printf("\n Indice non presente");}
    else
        stampaDetenuto(vd->v[indice-1]);
}
//stampa del singolo detenuto (stampa solo il primo inserimento al momento)
void stampaDetenuto(RecordSoggetto soggetto){

    printf("\nNome: %s", soggetto.nome);
    printf("\nCognome:%s", soggetto.cognome);
    printf("\nAltezza:%d", soggetto.altezza);
    printf("\nPeso: kg %.2f",soggetto.peso);
    stampaVettoreColoreOcchi(soggetto.coloreOcchi, DIM_COLORE);
    stampaVettoreColoreCapelli(soggetto.coloreCapelli, DIM_COLORE);
    stampaLunghezzaCapelli(soggetto.capelli);
    stampaBarba(soggetto.barba);
    stampaCicatrici(soggetto.cicatrice);
    stampaVettoreFingerPrint(soggetto.chiaveImprontaDigitale, DIM_IMPRONTA);
    stampaStatoSoggetto(soggetto.stato);
    printf("\nCoordinate Gps Ultima Posizione: \tlatitudine %.2lf, longitudine %.2lf", soggetto.posizione.latitudine,soggetto.posizione.longitudine);
    printf("\nResidenza: %s", soggetto.residenza);
}

//stampa tutti i record nel vettore
void stampaVettoreDinamico(VettoreDinamico *vd) { //da vedere la stampa generale del vettore.
    int i;

    for(i=0; i<=vd->nDetenuti-1; i++){
        //RecordSoggetto d = vd->v[i];
        stampaDetenuto(vd->v[i]);
    }

}

//al momnento non funziona, ma dovrebbe stampare i caratteri di un vettore di caratteri.
void stampaVettoreColoreOcchi(char vd[], int dim){
    int i;
    printf("\nCodice colore degli Occhi:\t  ");
    for (i=0; i<dim; i++){
        printf("[%c]",vd[i]);
    }
}
void stampaVettoreColoreCapelli(char vd[], int dim){
    int i;
    printf("\nCodice colore dei Capelli:\t  ");
    for (i=0; i<dim; i++){
        printf("[%c]",vd[i]);
    }
}

void stampaVettoreFingerPrint(char vd[], int dim){
    int i;
    printf("\nChiave impronta digitale: ");
    for (i=0; i<dim; i++){
        printf("[%c]",vd[i]);
    }
}

void stampaLunghezzaCapelli(LunghezzaCapelli e) {
    switch (e) {
        case CORTI:
            printf("\nIl Soggetto ha i capelli\t CORTI");
            break;
        case MEDI:
            printf("\nIl Soggetto ha i capelli\t MEDI");
            break;
        case LUNGHI:
            printf("\nIl Soggetto ha i capelli\t LUNGHI");
            break;
        case ALTRO:
            printf("\nIl Soggetto ha i capelli\t ALTRO, non specificato");
            break;
        default:
            printf("\nInserimento nel recordDetenuto non valido!");
    }
}
void stampaBarba(bool barbuto){
    if (barbuto == true){
        printf("\nIl soggetto ha la barba");
    }else
        printf("\nIl soggetto non ha la barba");
}
void stampaCicatrici(bool cicatrici){
    if (cicatrici == true){
        printf("\nIl soggetto ha cicatrici riconoscibili");
    }else
        printf("\nIl soggetto NON ha cicatrici");
}
void stampaStatoSoggetto(StatoSoggetto e) {
    switch (e) {
        case LIBERO:
            printf("\nIl Soggetto risulta\t Libero");
            break;
        case RICERCATO:
            printf("\nIl Soggetto risulta\t Ricercato");
            break;
        case ARRESTATO:
            printf("\nIl Soggetto risulta\t Arrestato");
            break;
        case EVASO:
            printf("\nIl Soggetto risulta\t Evaso");
            break;
        default:
            printf("\nInserimento nel recordDetenuto non valido!");
    }
}