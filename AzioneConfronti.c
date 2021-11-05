//
// Created by Giancarlo on 05/06/2021.
//

#include "AzioneConfronti.h"
#include "libreria_primaria.h"
#include "stampe.h"

/**
 * confronta due differenti recordSoggetto
 * @param s vettore
 * @return percentuale di similiarità mi è costata un giorno di lavoro
 */
int confrontoGenerale(VettoreDinamico *vd){
    RecordSoggetto e1, e2;
    int contatore=0;
    int percentuale=0;
    int y , j;

    printf("\nInserisci primo record da cui fare confronto");
    scanf("%d", &y);
    printf("\nInserisci primo record da cui fare confronto");
    scanf("%d", &j);
    e1= vd->v[y];
    e2= vd->v[j];

    contatore += confrontoVettori(DIM_NOM, e1.nome, e2.nome);
    contatore += confrontoVettori ( DIM_NOM, e1.cognome , e2.cognome);
    contatore += confrontoNum (e1.altezza, e2.altezza);
    contatore += confrontoNum (e1.peso, e2.peso);
    contatore += confrontoNum (e1.stato, e2.stato);
    contatore += confrontoNum (e1.capelli, e2.capelli);
    contatore += verificaBool (e1.cicatrice, e2.cicatrice);
    contatore += verificaBool (e1.barba , e2.barba  );
    if ((confrontoNum (e1.posizione.latitudine, e2.posizione.latitudine) )!= 0 & (confrontoNum(e1.posizione.longitudine, e2.posizione.longitudine)) !=0)
        contatore++;
    contatore += confrontoVettori (DIM_COLORE, e1.coloreOcchi, e2.coloreOcchi);
    contatore += confrontoVettori (DIM_COLORE, e1.coloreCapelli, e2.coloreCapelli);
    contatore += confrontoString (e1.residenza, e2.residenza );
    contatore += confrontoVettori( DIM_IMPRONTA, e1.chiaveImprontaDigitale, e2.chiaveImprontaDigitale);

    percentuale= (contatore)*(100/13);
    printf("\n Percentuale--> %d%%", percentuale);
    return percentuale;
}

//confronto tra stringhe
int confrontoString(char string1[], char string2[]){
    if (strcmp(string1, string2) != 0){
        return 0;}
    else
        return 1;
}
//confronto tra due numeri
int confrontoNum(double x, double y) {
    if (x != y) {
        return 0;
    } else
        return 1;
}

//trasforma un vettore in stringa
void vettoreInString(int dim, char v[], char *e){
    snprintf (v, sizeof(dim), e);
}

int verificaBool (bool e1, bool e2){
    if (((e1==true)&&(e2==true))||((e1==false)&&(e2==false)))
        return 1;
    else
        return 0;
}

//booleano per individuare elemento maggiore tra due
_Bool confrontoMaggiore(RecordSoggetto soggetto1[], RecordSoggetto soggetto2[]){
    if(strcmp(soggetto1->nome, soggetto2->nome)>0)
        return true;
    else if (strcmp(soggetto1->nome, soggetto2->nome)<0)
        return false;
    else if (strcmp(soggetto1->cognome, soggetto2->cognome)>0)
        return true;
    else if (strcmp(soggetto1->cognome, soggetto2->cognome)<0)
        return false;
}

//booleano per fare un confronto di uguaglianza tra due soggetti del Record
_Bool confrontoSoggetti(RecordSoggetto soggetto1,RecordSoggetto soggetto2){
    if(strcmp(soggetto1.nome, soggetto2.nome) == 0){
        if(strcmp(soggetto1.cognome, soggetto2.cognome) == 0)
            return true;}
    else
            return false;
}
//confronto tra due vettori convertiti in stringa
int confrontoVettori(int dim, char v1[], char v2[]){
    char string1[dim];
    char string2[dim];
    int risultatoConfronto;
    vettoreInString(dim, v1, string1);
    vettoreInString(dim, v2, string2);
    confrontoString(string1, string2);
    risultatoConfronto = confrontoString(string1, string2);
    if (risultatoConfronto==0){
        return 0;}
    else
        return 1;
}

void azioneRicerca(VettoreDinamico *vd){
    char string[DIM_NOM+1];
    printf("\nInserisci elementi per la ricerca (stringa, nomi et c): ");
    scanf("%s", string);
    ricercaFrammentoStringa(vd, string);
}

//cerca e stampa i recordDetenuti che contengono nel campo nome o nel campo cognome
//il frammento di stringa attraverso la funzione strstr().

void ricercaFrammentoStringa(VettoreDinamico *vd, char *string){
    int i;
    RecordSoggetto variabileAppoggio;

    for(i=0; i<dimensioneVettore(vd); i++){
        variabileAppoggio= recuperaElemento(vd, i);
        if (strstr(variabileAppoggio.nome, string)!=NULL || strstr(variabileAppoggio.cognome, string)!=NULL)
            stampaDetenuto(variabileAppoggio);

    }
}

//recupero di un valore nel vettore in una data posizione

RecordSoggetto recuperaElemento(VettoreDinamico *vd, int indice){
    if (!vettoreVuoto(vd) && (indice < vd->nDetenuti)){
        return vd->v[indice];}
    else
        printf("Non è stato possibile recuperare il valore1") ;
}


void azioneOrdinamentoAlfabetico(VettoreDinamico *vd) {
    int i;
    RecordSoggetto c;
//algoritmo bubble sort applicato alle stringe
    while (vd->nDetenuti > 1) {
        for (i = 0; i < vd->nDetenuti - 1; i++) {
            if (strcmp(vd->v[i].cognome, vd->v[i + 1].cognome) > 0){
                c = vd->v[i];
                vd->v[i] = vd->v[i + 1];
                vd->v[i + 1] = c;
            }
        }
        vd->nDetenuti --;
    }
//stampa degli elementi ordinati
    printf("\n Record stampato in ordine alfabetico");
    for(i=0; i<vd->nDetenuti ; i++) {
        stampaDetenuto(vd->v[i]);
    }
    printf("\n");
}
