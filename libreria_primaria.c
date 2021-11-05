//
// Created by Giancarlo on 30/05/2021.
//

#include "libreria_primaria.h"
#include "AzioneConfronti.h"
#include "stampe.h"
#include "controlli.h"

//menu d'avvio
void menuAvvio(){

    srand(time(NULL));
    VettoreDinamico vdDetenuti;
    MenuScelta scelta;
    inizializzaVettoreDinamico(&vdDetenuti);
    benvenuto();


    do{
        intestazione();
        scanf("%d", &scelta);
        svuotaBuffer();
        switch(scelta){
            case INSERISCI_RECORD:
               azioneInserisciRecord(&vdDetenuti);
                break;
            case GENERA_CASUALMENTE_RECORD:
                azioneInserisciRecordGenerato(&vdDetenuti);
                break;
            case CARICA_DATI_DA_FILE:
                printf("\nlo sviluppatore al momento non ha concluso questa task");
                break;
            case ELIMINAZIONE:
                azioneCancellaRecordDetenuto(&vdDetenuti);
                break;
            case RICERCA:
                azioneRicerca(&vdDetenuti);
                break;
            case CONFRONTO:
                confrontoGenerale(&vdDetenuti);
                break;
            case ORDINAMENTO_ALFABETICO:
                azioneOrdinamentoAlfabetico(&vdDetenuti);
                break;
                break;
            case STAMP_RECORD_SINGOLO:
                stampaSingoloDetenuto(&vdDetenuti);
                break;
            case STAMPA_GENERALE:
                stampaVettoreDinamico(&vdDetenuti);
                break;
            case ESCI:
                printf("\n\n\t\t\t\t\t\t\tArrivederci al prossimo Criminale! :) \n\n\n\n");
                exit(0);
            default:
                printf("no buono");
                break;
        }

    }while(scelta != ESCI);
}

// funzionalità acquisizioni dati
RecordSoggetto acquisisciDatiDetenuto() {
    RecordSoggetto d;

//Acquisizione nome
    controlloInputNome(&d);

//Acquisizione cognome
    controlloInputCognome(&d);

//Acquisizione altezza
    controlloInputAltezza(&d);

//Acquisizione Peso
    controlloInputPeso(&d);

//Acquisizione Colore degli occhi
    controlloInputColoreOcchi(&d);

//Acquisizione Colore dei capelli
    controlloInputColoreCapelli(&d);


//Acquisizione Lunghezza dei capelli
    controlloInputLunghezzaCapelli(&d);

//Acquisizione Barba
    inputBooleanoBarba(&d);

//Acquisizione Cicatrici
    inputBooleanoCicatrici(&d);

//Acquisizione Chiave impronta digitale utilizzare un while
    controlloInputFingerPrint(&d);

    //Acquisizione posizione del detenuto
    controlloPosizioneGpsLatitudine(&d);

    //Acquisizione posizione del detenuto
    controlloPosizioneGpsLongitudine(&d);

    //Acquisizione Stato del Soggetto
    controlloInputStatoSoggetto(&d);

    //Acquisizione residenza
    controlloInputResidenza(&d);

    return d;
}
RecordSoggetto acquisisciRecordGenerato(){
    RecordSoggetto d;

    generaNomiCasuale(&d);
    generaCognomiCasuale(&d);
    generaAltezza(&d);
    generaPeso(&d);
    generaCicatrici(&d);
    generaBarba(&d);
    generaLunghezzaCapelli(&d);
    generaPosizioneGps(&d);
    generaResidenza(&d);
    generaStatoSoggetto(&d);
}

void azioneInserisciRecord(VettoreDinamico *vd){
    RecordSoggetto detenuto;
    detenuto = acquisisciDatiDetenuto();
    aggiungiDetenuto(vd, detenuto);
}
void azioneInserisciRecordGenerato(VettoreDinamico *vd){
    RecordSoggetto detenuto;
    detenuto = acquisisciRecordGenerato();
    aggiungiDetenuto(vd, detenuto);
}
void inizializzaVettoreDinamico(VettoreDinamico *vd){
    vd->v = NULL;
    vd->nDetenuti = 0;
}
void aggiungiDetenuto(VettoreDinamico *vd, RecordSoggetto soggetto) {

    vd->nDetenuti++;
    /* riservo uno spazio in memoria per il mio vettore dinamico*/
    if (vd->v == NULL) {
        vd->v = (RecordSoggetto *) malloc( vd->nDetenuti * sizeof(RecordSoggetto));
        settaElemento(vd, vd->nDetenuti, soggetto);


    } else {
        vd->v = (RecordSoggetto *) realloc(vd->v, vd->nDetenuti * sizeof(RecordSoggetto));
        settaElemento(vd, vd->nDetenuti, soggetto);
    }

    if (vd->v == NULL)
        exit(-1);
    vd->v[vd->nDetenuti - 1] = soggetto;
    printf("\n\nL'inserimento è avvenuto con successo!");
}
void settaElemento(VettoreDinamico *vd, int indice, RecordSoggetto soggetto){
    vd->v[indice] = soggetto;

}





/**
 * Restituisce la dimensione dell'array
 * @param vettore Puntatore al vettore
 * @return Attuale dimensione del vettore dinamico
 */
int dimensioneVettore(VettoreDinamico *vd){
    return vd->nDetenuti;
}

/**
 * Alloca in un indice del vettore i dati di un detenuto
 * @param vettore Puntatore al vettore, l'indice, il detenuto
 */
void nuovaPosizioneDetenuto(VettoreDinamico *vd, int indice, RecordSoggetto d){
    if (indice < vd->nDetenuti)
        vd->v[indice] = d;
    else
        printf("\n Indice passato come parametro è maggiore della dimensione del vettore");
}


/**
 * il nome è autoevidente: riduce di uno la dimensione totale,
 * la realloc mi ridimensiona il vettore
 */
void rimuoviDetenutoInCoda(VettoreDinamico *vd){
    if(!vettoreVuoto(vd)){
        vd->nDetenuti--;
        vd->v = (RecordSoggetto *) realloc(vd->v, vd->nDetenuti *sizeof(RecordSoggetto));
    }
}

void azioneCancellaRecordDetenuto(VettoreDinamico *vd){
    int indice;
    printf("Inserisci la posizione del detenuto che vuoi eliminare: ");
    scanf("%d", &indice);
    rimuoviDetenutoInPosizione(vd, indice);
    printf("La rimozione è avvenuta con successo!");
}

/**
 * mi permette di eliminare un elemento nella iesima posizione del vettore,
 * @param un puntatore al vettore, e l'indice.
 * Copio a ritroso tutti gli elementi da una data posizione in poi.
 */

void rimuoviDetenutoInPosizione(VettoreDinamico *vd, int indice){
    int i;
    for(i=indice; i<(vd->nDetenuti-1); i++){
        nuovaPosizioneDetenuto(vd, i, vd->v[i+1]);
    }rimuoviDetenutoInCoda(vd);
}


/**
 * Svuota buffer per evitare problemi di acquisizione per successive stringhe o char. Se eseguiamo questa funzione
 * dopo ogni scanf siamo sicuri che il buffer sarà svuotato fino al prossimo carattere '\n'.
 * @return False se sono stati trovati valori diversi dal singolo '\n' nel buffer, altrimenti True
 */

_Bool vettoreVuoto(VettoreDinamico *vd) {
    return vd->v == NULL;
}

FILE *chiudiFile(FILE * fp){
    if (fp != NULL)
        fclose(fp);
    return NULL;
}

/**
void caricaDati(VettoreDinamico *vd, FILE *fp){
    apriFile("Database.dat", "rb");
    leggiFileBinario(vd, apriFile("Database.dat", "rb"));
    chiudiFile(apriFile("Database.dat", "rb"));
    printf("File caricato");
}*/


/** generazione casuale
 *
 *
 */

int generaInteroCasuale(int min, int max){
    int numero;
    numero = min + rand()% max;
    return numero;
}
float generaFloatCasuale () {
    float a, b;
    float numeroReale;

    a = 40 + rand() % 80;
    b = 40 + rand() % 80;
    numeroReale = ((float) (rand())) / RAND_MAX; //ora il numero Reale sta tra 0 e 1
    numeroReale *= (b - a); //ora numeroReale sta tra 0 e b-a
    numeroReale += a; //ora numeroReale sta tra a e b
    return numeroReale;
}


void generaNomiCasuale(RecordSoggetto *soggetto){
    int i;
    char listaNomi [10][30]= {"Armando", "Fabrizio","Corrado", "JohnCarlo", "PierSilvione", "NoBuono","Mario","Pirata", "Davide", "Impostore"};
    i = generaInteroCasuale(0,10);
    strcpy(soggetto->nome, listaNomi[i]);
    printf("\nNome: %s", soggetto->nome);
}
void generaCognomiCasuale(RecordSoggetto *soggetto){
    int i;
    char listaNomi [10][30] = {"Apontrandolfo", "LoBello","Pacciani", "Riina", "Cavalera", "LoSquartatore","Squalo","Campana", "Tornese", "Misseri"};
    i = generaInteroCasuale(0,10);
    strcpy(soggetto->cognome, listaNomi[i]);
    printf("\nCognome:%s", soggetto->cognome);
}



void generaAltezza(RecordSoggetto *soggetto){
    soggetto->altezza = generaInteroCasuale(LIMITE_ALTEZZA_MIN, LIMITE_ALTEZZA_MAX);
    printf("\nAltezza:%d", soggetto->altezza);
}

void generaPeso(RecordSoggetto *soggetto){
    soggetto->peso = generaFloatCasuale();
    printf("\nPeso: kg %.2f",soggetto->peso);
}
void generaBarba(RecordSoggetto *soggetto){
    soggetto->barba = generaInteroCasuale(0,1);
    stampaBarba(soggetto->barba);
}
void generaCicatrici(RecordSoggetto *soggetto){
    soggetto->cicatrice = generaInteroCasuale(0,1);
    stampaCicatrici(soggetto->cicatrice);
}

void generaLunghezzaCapelli(RecordSoggetto *soggetto){
    soggetto->capelli = generaInteroCasuale(ENUM_MIN, ENUM_MAX);
    stampaLunghezzaCapelli(soggetto->capelli);
}

void generaStatoSoggetto(RecordSoggetto *soggetto){
    soggetto->stato = generaInteroCasuale(ENUM_MIN, ENUM_MAX);
    stampaStatoSoggetto(soggetto->stato);
}
void generaResidenza(RecordSoggetto *soggetto){
    int i;
    char listaStati [10][50] = {"Italia,Lecce,Carmiano", "Spagna,Cordova,ElFuego","Cile,Conception,Chiguayante", "Italia,Roma,Acilia", "Italia, Milano, CasalPusterlengo", "Italia,Lodi, Codogno","Italia, Firenze, SestoFiorentino","Bulgari, Budapest, TarantNuestr", "Italia, Lecce, Giorgilorio di Surbo", "Italia, Lecce, Borgnagne di Melendugno"};
    i = generaInteroCasuale(0,10);
    strcpy(soggetto->residenza, listaStati[i]);
    printf("\nResidenza: %s", soggetto->residenza);

}
/**void generaColoreOcchi(RecordSoggetto *soggetto) { //da sviluppare
    int i,n;
    char p[];
    for (i=0; i<DIM_IMPRONTA; i++) {
        n = generaInteroCasuale(0,9);
        scanf("%6[^\n]c", (p[i]);
    }
    for (i=0; i<DIM_IMPRONTA; i++) {
        scanf("%6[^\n]c", (soggetto[i].chiaveImprontaDigitale));
    }
    stampaVettoreFingerPrint(soggetto->chiaveImprontaDigitale, DIM_IMPRONTA);
}*/

void generaPosizioneGps(RecordSoggetto *soggetto){
    soggetto->posizione.longitudine= generaInteroCasuale(GPS_MIN, GPS_MAX);
    soggetto->posizione.longitudine= generaInteroCasuale(GPS_MIN, GPS_MAX);
    printf("\nLe coordinate GPS dell'ultima posizione del soggetto sono\n\tLONGITUDINE: %.2lf \tLATITUDINE %.2lf", soggetto->posizione.longitudine,soggetto->posizione.latitudine);
}


//procedura converte dati generati casualmente in stringa di esadecimali del numero di cifre desiderato
void covertiStringaEsadecimale(char *stringaEsadecimale, const char *caratteriCasuali, int nCifre) {
    const char xx[]= "ABCDEF0123456789";
    while (--nCifre >= 0) stringaEsadecimale[nCifre] = xx[(caratteriCasuali[nCifre>>1] >> ((1 - (nCifre&1)) << 2)) & 0xF];
}
//procedura che genera codici esadecimali
void generaCodiceEsadecimaleColore(){

    typedef unsigned char caratteriPerConversione;
    int i;
    caratteriPerConversione caratteriCasuali[15];//vettore da riempire con dati casuali
    for (i = 0; i < 15; i++) {
        caratteriCasuali[i] = 1 + rand() % 100;}
    int n = sizeof(caratteriCasuali) << 1;//operazioni sulla lunghezza del vettore
    char stringaEsadecimale[n + 1];//dichiarazione della stringa che andremo a riempire con la funzione successiva

    covertiStringaEsadecimale(stringaEsadecimale, caratteriCasuali, 6);//ncifre è la lunghezza desiderata del codice
    stringaEsadecimale[n] = 0;
}

//procedura che genera codici esadecimali
void generaCodiceEsadecimaleFingerPrint(){

    typedef unsigned char caratteriPerConversione;
    int i;
    caratteriPerConversione caratteriCasuali[15];//vettore da riempire con dati casuali
    for (i = 0; i < 15; i++) {
        caratteriCasuali[i] = 1 + rand() % 100;}
    int n = sizeof(caratteriCasuali) << 1;//operazioni sulla lunghezza del vettore
    char stringaEsadecimale[n + 1];//dichiarazione della stringa che andremo a riempire con la funzione successiva

    covertiStringaEsadecimale(stringaEsadecimale, caratteriCasuali, 16); //ncifre è la lunghezza desiderata del codice
    stringaEsadecimale[n] = 0;
    printf("%s\n", stringaEsadecimale);
}


